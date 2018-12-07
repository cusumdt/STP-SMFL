@echo off

echo Copiando Archivos...

set SolutionDir=%~1
set TargetDir=%~2

echo SolutionDir
echo TargetDir

XCOPY "%SolutionDir%libs\SFML-2.5.1\bin\release\*.dll" "%TargetDir%" /e /h /y /s

XCOPY "%SolutionDir%libs\STP\bin\release\*.dll" "%TargetDir%" /e /h /y /s

XCOPY "%SolutionDir%libs\TGUI-0.8\bin\release\*.dll" "%TargetDir%" /e /h /y /s

MKDIR "%TargetDir%res"
XCOPY "%SolutionDir%res" "%TargetDir%res" /e /h /y /s