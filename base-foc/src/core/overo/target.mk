include $(PRG_DIR)/../target.inc

LD_TEXT_ADDR = 0x80140000

REQUIRES += arm foc_overo
SRC_CC   += arm/platform_arm.cc

vpath io_port_session_component.cc $(GEN_CORE_DIR)/arm

