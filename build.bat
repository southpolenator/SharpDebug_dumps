@ECHO OFF
pushd Source\ExceptionDumper32
dotnet restore
dotnet msbuild
popd
msbuild Source\NativeDumpTest\NativeDumpTest.x64.vcxproj /p:Configuration=Debug;Platform=x64 /verbosity:minimal /nologo
msbuild Source\NativeDumpTest\NativeDumpTest.x64.Release.vcxproj /p:Configuration=Release;Platform=x64 /verbosity:minimal /nologo
msbuild Source\NativeDumpTest\NativeDumpTest.x86.vcxproj /p:Configuration=Debug;Platform=Win32 /verbosity:minimal /nologo
msbuild Source\NativeDumpTest\NativeDumpTest.x86.Release.vcxproj /p:Configuration=Release;Platform=Win32 /verbosity:minimal /nologo
