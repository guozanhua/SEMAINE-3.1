@echo off
set BINDIR=%~dp0%

set MARYDIR="$BINDIR\..\MARY399alpha"

if not exist %MARYDIR% (
  echo.MARY directory not found in $MARYDIR. Cannot start.
  goto end
)

set JARDIR=%BINDIR%..\java\lib

if not exist %JARDIR%\semaine.jar (
  echo.No semaine.jar -- you need to do 'ant jars' in the java folder first!
  goto end
)

set CONFIG=%1%
if %CONFIG%a==a (
  set CONFDIR=%BINDIR%..\java\config
  set CONFIG=%CONFDIR%\speech2face.config
)

set JMS_URL_SETTING=""
if %CMS_URL%a==a (
  echo.Connecting to JMS server at %CMS_URL%
  set JMS_URL_SETTING="-Djms.url=%CMS_URL%"
fi


echo.Starting SEMAINE system as: 'java -Xmx400m %JMS_URL_SETTING% -classpath %JARDIR%\semaine.jar;%JARDIR%\semaine-mary.jar;%JARDIR%\semaine-dialogue.jar -Dmary.base="%MARYDIR%" eu.semaine.system.ComponentRunner %CONFIG%'

java -Xmx400m %JMS_URL_SETTING% -classpath %JARDIR%\semaine.jar;%JARDIR%\semaine-mary.jar;%JARDIR%\semaine-dialogue.jar -Dmary.base="%MARYDIR%" eu.semaine.system.ComponentRunner %CONFIG%

:: goto target:

:end