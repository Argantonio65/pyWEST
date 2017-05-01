CALL cpp -I "C:\Users\localadmin.TUD278183\Desktop\GitProjects\pyWEST\WESTforIUWS_modelLibrary_little\Models" -DINDEX_OF_FEED_LAYER_BURGER=25 -DNR_OF_LAYERS_BURGER=90 -DNR_OF_LAYERS_PLUS_ONE_BURGER=91 -DNR_OF_LAYERS_PLUS_TWO_BURGER=92 -DNR_OF_LAYERS_PLUS_THREE_BURGER=93 -DNR_OF_LAYERS_PLUS_FOUR_BURGER=94 -DINDEX_OF_FEED_LAYER=5 -DASM2dModTemp -DNR_OF_LAYERS=10 -DNR_OF_LAYERS_PLUS_ONE=11 -DNR_OF_LAYERS_BUT_ONE=9 "Model_dummy_1.Project.msl" "Model_dummy_1.Project.cpp.msl"
@IF %ERRORLEVEL% NEQ 0 GOTO End
CALL tmsl -ut "d" -i "..\WESTforIUWS_modelLibrary_little\External\External" "Model_dummy_1.Project.cpp.msl"
@IF %ERRORLEVEL% NEQ 0 GOTO End
CALL tbuild -S "..\WESTforIUWS_modelLibrary_little\External\External" -B "" _Model_dummy_1_
@IF %ERRORLEVEL% NEQ 0 GOTO End
:End
EXIT /B %ERRORLEVEL%
