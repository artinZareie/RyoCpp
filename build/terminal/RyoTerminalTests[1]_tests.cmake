add_test([=[Terminal.StylizeApplyTests]=]  /home/artin/Documents/Projects/Ryo/build/bin/RyoTerminalTests [==[--gtest_filter=Terminal.StylizeApplyTests]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[Terminal.StylizeApplyTests]=]  PROPERTIES WORKING_DIRECTORY /home/artin/Documents/Projects/Ryo/build/terminal SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  RyoTerminalTests_TESTS Terminal.StylizeApplyTests)
