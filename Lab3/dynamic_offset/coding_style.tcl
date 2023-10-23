#Lab3-Dynamic Offset
go new
solution file set {$PROJECT_HOME/test.cpp} -exclude false
solution file set {$PROJECT_HOME/test_orig.cpp} -exclude true
go analyze
directive set -DESIGN_HIERARCHY test
go assembly
directive set /test/core/main -PIPELINE_INIT_INTERVAL 1
go extract