#Lab3-Dynamic Offset
solution file add ./test_orig.cpp
solution file add ./tb.cpp -exclude true
solution file add ./test.cpp -exclude true
go analyze
go compile
solution library add nangate-45nm_beh -- -rtlsyntool OasysRTL -vendor Nangate -technology 045nm
go libraries
directive set -CLOCKS {clk {-CLOCK_PERIOD 2 -CLOCK_EDGE rising -CLOCK_HIGH_TIME 1 -CLOCK_OFFSET 0.000000 -CLOCK_UNCERTAINTY 0.0 -RESET_KIND sync -RESET_SYNC_NAME rst -RESET_SYNC_ACTIVE high -RESET_ASYNC_NAME arst_n -RESET_ASYNC_ACTIVE low -ENABLE_NAME {} -ENABLE_ACTIVE high}}
go assembly
directive set /test_orig_wrapper/core/main -PIPELINE_INIT_INTERVAL 1
go allocate
go extract
go new
solution file set {$PROJECT_HOME/test_orig.cpp} -exclude true
solution file set {$PROJECT_HOME/test.cpp} -exclude false
go analyze
directive set -DESIGN_HIERARCHY test_wrapper
go libraries
go assembly
directive set /test_wrapper/core/main -PIPELINE_INIT_INTERVAL 1
go extract

