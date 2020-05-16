LOCAL_PATH := $(call my-dir)

FMOD_API_ROOT := $(LOCAL_PATH)/../../../../..

#
# FMOD Shared Library
#
include $(CLEAR_VARS)

LOCAL_MODULE            := fmod
LOCAL_SRC_FILES         := $(FMOD_API_ROOT)/api/core/lib/$(TARGET_ARCH_ABI)/libfmod$(FMOD_LIB_SUFFIX).so
LOCAL_EXPORT_C_INCLUDES := $(FMOD_API_ROOT)/api/core/inc


include $(PREBUILT_SHARED_LIBRARY)

#
# Example Library
#
include $(CLEAR_VARS)

LOCAL_MODULE            := example
LOCAL_SRC_FILES         := src/main/cpp/common_platform.cpp src/main/cpp/common.cpp src/main/cpp/dsp_inspector.cpp
LOCAL_C_INCLUDES        := src/main/cpp
LOCAL_SHARED_LIBRARIES  := fmod

include $(BUILD_SHARED_LIBRARY)

