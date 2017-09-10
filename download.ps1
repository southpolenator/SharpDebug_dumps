$webClient = New-Object System.Net.WebClient
#$url = "https://ci.appveyor.com/api/projects/southpolenator/windbgcs-dumps/artifacts/Source/NativeDumpTest/bin/NativeDumpTest.x64.VS2013.exe?job=Image%3A%20Visual%20Studio%202013"
foreach ($url in (Get-Content "urls.txt"))
{
    $filename = [regex]::match($url, '/([^/?]*)[?]').Groups[1].Value
    $webClient.DownloadFile($url, $filename);
}
