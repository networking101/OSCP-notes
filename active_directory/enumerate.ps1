$d=[System.DirectoryServices.ActiveDirectory.Domain]::GetCurrentDomain();
$q=("LDAP://"+($d.PdcRoleOwner).Name+"/DC="+($d.Name.Replace('.',',DC=')));
$s=New-Object System.DirectoryServices.DirectorySearcher([ADSI]$q);
$s.SearchRoot=(New-Object System.DirectoryServices.DirectoryEntry);
write-host "-- COMPUTERS --";
$s.filter="(objectCategory=computer)";$s.FindAll()|?{write-host $_.Path};
write-host "-- USERS --";
$s.filter="(objectCategory=person)";$s.FindAll()|?{write-host $_.Path};
write-host "-- SERVICES --";
$s.filter="(serviceprincipalname=*)";$s.FindAll()|?{write-host $_.Path};
write-host "-- GROUPS --";
$s.filter="(objectCategory=group)";$s.FindAll()|?{write-host $_.Path};
write-host "-- MEMBERSHIP --";
function _r {
  param($o,$m);
  if ($o.Properties.member -ne $null) {
    $lm=[System.Collections.ArrayList]@();
    $o.Properties.member|?{$lm.add($_.split(",")[0].replace("CN=",""))};
    $lm=$lm|select -unique; 
    $m.add((New-Object psobject -Property @{
      OU = $o.Properties.name[0]
      M = [string]::Join(", ",$lm)
    }));
    $lm | ?{
      $s.filter=[string]::Format("(name={0})",$_);
      $s.FindAll()|?{_r $_ $m | out-null};
    }
  }
}
$m=[System.Collections.ArrayList]@();
$s.FindAll()|?{_r $_ $m | out-null};
$m|sort-object OU -unique|?{write-host ([string]::Format("[OU] {0}: {1}",$_.OU,$_.M))};