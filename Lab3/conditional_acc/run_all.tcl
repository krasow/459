#Lab3 - conditional acc
solution new -state initial
solution options defaults
solution options set /Output/GenerateCycleNetlist false
solution options set /Flows/SCVerify/USE_CCS_BLOCK true
solution file add ./test_orig.cpp -type C++
solution file add ./test.cpp -type C++ -exclude true
solution file add ./tb.cpp -type C++ -exclude true
directive set -DESIGN_GOAL area
directive set -OLD_SCHED false
directive set -SPECULATE true
directive set -MERGEABLE true
directive set -REGISTER_THRESHOLD 256
directive set -MEM_MAP_THRESHOLD 32
directive set -LOGIC_OPT false
directive set -FSM_ENCODING none
directive set -FSM_BINARY_ENCODING_THRESHOLD 64
directive set -REG_MAX_FANOUT 0
directive set -NO_X_ASSIGNMENTS true
directive set -SAFE_FSM false
directive set -REGISTER_SHARING_MAX_WIDTH_DIFFERENCE 8
directive set -REGISTER_SHARING_LIMIT 0
directive set -ASSIGN_OVERHEAD 0
directive set -TIMING_CHECKS true
directive set -MUXPATH true
directive set -REALLOC true
directive set -UNROLL no
directive set -IO_MODE super
directive set -CHAN_IO_PROTOCOL standard
directive set -ARRAY_SIZE 1024
directive set -REGISTER_IDLE_SIGNAL false
directive set -IDLE_SIGNAL {}
directive set -STALL_FLAG false
directive set -TRANSACTION_DONE_SIGNAL true
directive set -DONE_FLAG {}
directive set -READY_FLAG {}
directive set -START_FLAG {}
directive set -BLOCK_SYNC none
directive set -TRANSACTION_SYNC ready
directive set -DATA_SYNC none
directive set -RESET_CLEARS_ALL_REGS true
directive set -CLOCK_OVERHEAD 20.000000
directive set -OPT_CONST_MULTS use_library
directive set -CHARACTERIZE_ROM false
directive set -PROTOTYPE_ROM true
directive set -ROM_THRESHOLD 64
directive set -CLUSTER_ADDTREE_IN_COUNT_THRESHOLD 0
directive set -CLUSTER_OPT_CONSTANT_INPUTS true
directive set -CLUSTER_RTL_SYN false
directive set -CLUSTER_FAST_MODE false
directive set -CLUSTER_TYPE combinational
directive set -COMPGRADE fast
directive set -PIPELINE_RAMP_UP true
go new
#unpilined version
directive set -DESIGN_HIERARCHY test_orig
go analyze
solution library add nangate-45nm_beh -file {$MGC_HOME/pkgs/siflibs/nangate/nangate-45nm_beh.lib} -- -rtlsyntool OasysRTL
go libraries
directive set -CLOCKS {clk {-CLOCK_PERIOD 1.0 -CLOCK_EDGE rising -CLOCK_UNCERTAINTY 0.0 -CLOCK_HIGH_TIME 0.5 -RESET_SYNC_NAME rst -RESET_ASYNC_NAME arst_n -RESET_KIND sync -RESET_SYNC_ACTIVE high -RESET_ASYNC_ACTIVE low -ENABLE_ACTIVE high}}
go assembly
go extract
#pipeline the MAC loop for better performance
go assembly
directive set /test_orig/core/MAC -PIPELINE_INIT_INTERVAL 1
go extract
#pipeline the main loop
go assembly
directive set /test_orig/core/main -PIPELINE_INIT_INTERVAL 1
go extract
go assembly
#Unroll by 2
directive set /test_orig/core/MAC -UNROLL 2
directive set /test_orig/core/main -PIPELINE_INIT_INTERVAL 1
go architect
go extract
#unroll fully
go assembly
directive set /test_orig/core/MAC -UNROLL yes
directive set /test_orig/core/main -PIPELINE_INIT_INTERVAL 1
go architect
go extract
#Use opotmized version that makes the accumulate uncondtional
go new
solution file set {$PROJECT_HOME/test_orig.cpp} -exclude true
solution file set {$PROJECT_HOME/test.cpp} -exclude false
go analyze
directive set -DESIGN_HIERARCHY test
go assembly
directive set /test/core/main -PIPELINE_INIT_INTERVAL 1
directive set /test/core/main/MAC -UNROLL yes
go extract