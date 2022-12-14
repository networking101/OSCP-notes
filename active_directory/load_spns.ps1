Add-Type -AssemblyName System.IdentityModel;
$d=[System.DirectoryServices.ActiveDirectory.Domain]::GetCurrentDomain();
$q=("LDAP://"+($d.PdcRoleOwner).Name+"/DC="+($d.Name.Replace('.',',DC=')));
$s=New-Object System.DirectoryServices.DirectorySearcher([ADSI]$q);
$s.SearchRoot=(New-Object System.DirectoryServices.DirectoryEntry);
$s.filter="(serviceprincipalname=*)";$s.FindAll() | ?{
  $_.Properties['ServicePrincipalName'] | ? {
  	$SPN=$_.tostring();
  	write-host ("Loading SPN: $SPN");
  	New-Object System.IdentityModel.Tokens.KerberosRequestorSecurityToken -ArgumentList "$SPN";
  } | out-null;
};
