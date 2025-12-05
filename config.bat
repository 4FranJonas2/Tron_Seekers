set projectDir=%~1
set outDir=%~2

@echo off

echo "Copiando archivos..."

xcopy "%projectDir%\res" "%outDir%\res" /y /i /e /s