#include "unity_fixture.h"
#include "unity_config.h"
#include "fff.h"

#include "swo_print.h"

TEST_GROUP(SwoDebug);
volatile unsigned int Mock_ITM_STIM_U32;
volatile char Mock_ITM_STIM_U8;
volatile unsigned int Mock_ITM_ENA;
volatile unsigned int Mock_ITM_TCR;
DEFINE_FFF_GLOBALS;
FAKE_VALUE_FUNC(uint32_t, SWO_ReadITM_TCR)
FAKE_VALUE_FUNC(uint32_t, SWO_ReadITM_ENA)
FAKE_VALUE_FUNC(uint32_t, SWO_ReadITM_STIM_U8)
FAKE_VOID_FUNC(SWO_WriteITM_STIM_U8, char)

TEST_SETUP(SwoDebug) {
    ITM_STIM_U32 = 0;
    ITM_STIM_U8 = 0;
    ITM_ENA = 0;
    ITM_TCR = 0;
    RESET_FAKE(SWO_ReadITM_TCR);
    RESET_FAKE(SWO_ReadITM_ENA);
    RESET_FAKE(SWO_ReadITM_STIM_U8);
    RESET_FAKE(SWO_WriteITM_STIM_U8);
}

TEST_TEAR_DOWN(SwoDebug) {

}

TEST(SwoDebug, swoPrintPortsNotSetTCRSet) {
    SWO_PrintChar('c');
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_TCR_fake.call_count);
    TEST_ASSERT_EQUAL(0, SWO_ReadITM_ENA_fake.call_count);
    TEST_ASSERT_EQUAL(0, SWO_ReadITM_STIM_U8_fake.call_count);
    TEST_ASSERT_EQUAL(0, SWO_WriteITM_STIM_U8_fake.call_count);
}

TEST(SwoDebug, swoPrintPortsNotSetENASet) {
    ITM_TCR = 1U;
    SWO_ReadITM_TCR_fake.return_val = 1U;
    SWO_PrintChar('c');
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_TCR_fake.call_count);
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_ENA_fake.call_count);
    TEST_ASSERT_EQUAL(0, SWO_ReadITM_STIM_U8_fake.call_count);
    TEST_ASSERT_EQUAL(0, SWO_WriteITM_STIM_U8_fake.call_count);
}

TEST(SwoDebug, swoPrintReadItmSTIM) {
    SWO_ReadITM_TCR_fake.return_val = 1U;
    SWO_ReadITM_ENA_fake.return_val = 1U;
    SWO_ReadITM_STIM_U8_fake.return_val = 1U;
    SWO_PrintChar('c');
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_TCR_fake.call_count);
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_ENA_fake.call_count);
    TEST_ASSERT_EQUAL(1, SWO_ReadITM_STIM_U8_fake.call_count);
    TEST_ASSERT_EQUAL(1, SWO_WriteITM_STIM_U8_fake.call_count);
}

TEST(SwoDebug, swoPrintString) {
    SWO_ReadITM_TCR_fake.return_val = 1U;
    SWO_ReadITM_ENA_fake.return_val = 1U;
    SWO_ReadITM_STIM_U8_fake.return_val = 1U;
    SWO_PrintString("hell\n");
    TEST_ASSERT_EQUAL(5, SWO_ReadITM_TCR_fake.call_count);
    TEST_ASSERT_EQUAL(5, SWO_ReadITM_ENA_fake.call_count);
    TEST_ASSERT_EQUAL(5, SWO_ReadITM_STIM_U8_fake.call_count);
    TEST_ASSERT_EQUAL(5, SWO_WriteITM_STIM_U8_fake.call_count);
}


TEST_GROUP_RUNNER(SwoDebug)
{
   RUN_TEST_CASE(SwoDebug, swoPrintPortsNotSetTCRSet);
   RUN_TEST_CASE(SwoDebug, swoPrintPortsNotSetENASet);
   RUN_TEST_CASE(SwoDebug, swoPrintReadItmSTIM);
   RUN_TEST_CASE(SwoDebug, swoPrintString);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST_GROUP(SwoDebug);
    return UNITY_END();
}
