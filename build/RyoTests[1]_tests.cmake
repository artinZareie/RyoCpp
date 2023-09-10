add_test([=[Ryo.VersionCheck]=]  /home/artin/Documents/Projects/Ryo/build/bin/RyoTests [==[--gtest_filter=Ryo.VersionCheck]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Ryo.VersionCheck]=]  PROPERTIES WORKING_DIRECTORY /home/artin/Documents/Projects/Ryo/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  RyoTests_TESTS Ryo.VersionCheck)
