# NOTE: This makefile is designed to be run from one level up in the directory
# hierarchy compared to where it resides. For instance, if this makefile is
# located at 'output/build/Makefile', then it can be launched as:
# 'make -f build/Makefile' from the 'output' directory.

SHELL=/bin/bash
ifeq ($(CXX),)
  CXX=g++
endif
ifeq ($(CXX_LN),)
  CXX_LN=g++
endif
PKGCONFIG := /opt/ibm/InfoSphere_Streams/4.3.0.0/bin/dst-pe-pkg-config-alternative.sh
SPL_BUNDLE_BUILDER := /opt/ibm/InfoSphere_Streams/4.3.0.0/system/impl/bin/spl-bundle-builder
SO_INCLUDE := $(shell $(PKGCONFIG) --cflags dst-spl-pe-install)
SO_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install)
SO_STAND_LIB := $(shell $(PKGCONFIG) --libs dst-spl-pe-install-standalone)
SPL_CXXFLAGS = -Wall -Wno-unused -Wno-sign-compare
SPL_CXXFLAGS += -D_REENTRANT -fPIC -finline-functions -fmessage-length=0
SPL_CXXFLAGS += $(SO_INCLUDE) -O3 -DNDEBUG  -std=gnu++98 
SPL_LDFLAGS = $(SO_LIB)

SPL_TYPES = build/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.o \
            build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o \
            build/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.o \
            build/type/BeJwrMUwyKy5JTUypBAATwwPI.o \
            build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o \
            build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o \
            build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
            build/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.o \
            build/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.o \
            build/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.o \
            build/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.o \
            build/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.o 
SPL_FUNCTIONS = 
SPL_OPERATORS = build/operator/RawObservations.o \
                build/operator/DryHeatEvent.o \
                build/operator/SaunaEvent.o \
                build/operator/TempMEvent.o \
                build/operator/TempSteadyEvent.o \
                build/operator/OutputEvents.o \
                build/operator/JSONOutput.o \
                build/operator/HttpEvents.o \
                build/operator/HttpEventsDbg.o \
                build/operator/MaxMinTemp.o \
                build/operator/NewMaxMin.o \
                build/operator/JSONTempOutput.o \
                build/operator/WeatherSummary/WeatherStationReadings.o \
                build/operator/WeatherSummary/FilteredMissingValues.o \
                build/operator/WeatherSummary/FilteredOlderValues.o \
                build/operator/WeatherSummary/NoDuplicates.o \
                build/operator/WeatherSummary/TimeFilter.o \
                build/operator/WeatherSummary/FilteredAndPrepared.o 
SPL_SO_BINS = bin/RawObservations.so \
              bin/DryHeatEvent.so \
              bin/SaunaEvent.so \
              bin/TempMEvent.so \
              bin/TempSteadyEvent.so \
              bin/OutputEvents.so \
              bin/JSONOutput.so \
              bin/HttpEvents.so \
              bin/HttpEventsDbg.so \
              bin/MaxMinTemp.so \
              bin/NewMaxMin.so \
              bin/JSONTempOutput.so \
              bin/WeatherSummary.WeatherStationReadings.so \
              bin/WeatherSummary.FilteredMissingValues.so \
              bin/WeatherSummary.FilteredOlderValues.so \
              bin/WeatherSummary.NoDuplicates.so \
              bin/WeatherSummary.TimeFilter.so \
              bin/WeatherSummary.FilteredAndPrepared.so 

SPL_ADL_FILE = application.evdetect.adl

SPL_OUTPUT_DIR_ROOT = $(shell printf '%q' '/home/streamsadmin/workspace/evdetect/output/application.evdetect')
SPL_OUTPUT_DIR = $(shell printf '%q' 'BuildConfig')

.PHONY: distclean clean all types functions operators sos bundle toolkits standalone sablink

all: bin types functions operators sos standalone bundle sablink

distclean clean:
	@rm -fr bin/* build/type build/function build/operator build/bundle build/standalone application.evdetect.sab

bin:
	@mkdir -m 775 bin

types: $(SPL_TYPES)

build/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.o: \
	    src/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.h \
	    src/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{YYYYMMDDhhmmss,YYYY_MM_DD_hh_mm_ss,MM_DD_YYYY_hh_mm_...M_YYYY_hh_mm_ss_mmm}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.cpp

build/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.o: \
	    src/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.h \
	    src/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] enum{WindowMarker,FinalMarker}'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.cpp

build/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.o: \
	    src/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.h \
	    src/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<boolean rise,boolean drop,boolean deep>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.cpp

build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o: \
	    src/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.h \
	    src/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring jsonString>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.cpp

build/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.o: \
	    src/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.h \
	    src/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring rawObservation>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.cpp

build/type/BeJwrMUwyKy5JTUypBAATwwPI.o: \
	    src/type/BeJwrMUwyKy5JTUypBAATwwPI.h \
	    src/type/BeJwrMUwyKy5JTUypBAATwwPI.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<boolean steady>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMUwyKy5JTUypBAATwwPI.cpp

build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o: \
	    src/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.h \
	    src/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring stationCode,int64 observationTime,float32 t...int16 windGustKnots>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.cpp

build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o: \
	    src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h \
	    src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring stationCode,int64 observationTime,float32 t...int16 windGustKnots>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.cpp

build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o: \
	    src/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h \
	    src/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<tuple<rstring stationCode,int64 observationTime,flo...alues,rstring event>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.cpp

build/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.o: \
	    src/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.h \
	    src/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<float32 maxTemp,rstring maxTempStation,int64 maxObs... minObservationTime>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.cpp

build/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.o: \
	    src/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.h \
	    src/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring eventType,rstring eventStation,rstring eventTime>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.cpp

build/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.o: \
	    src/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.h \
	    src/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.cpp \
	    build/cppOptions \
	    | build/type
	@echo ' [CXX-type] tuple<rstring eventType,float32 maxTemp,rstring maxTempSt...ring minTempStation>'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.cpp

build/type:
	-@mkdir -m 775 build/type

operators: $(SPL_OPERATORS)

-include build/operator/RawObservations.d
build/operator/RawObservations.o: \
	    src/operator/RawObservations.h \
	    src/operator/RawObservations.cpp\
	    build/dep/operator/RawObservations.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] RawObservations'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streamsx.inet/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streamsx.inet/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/RawObservations.cpp

-include build/operator/DryHeatEvent.d
build/operator/DryHeatEvent.o: \
	    src/operator/DryHeatEvent.h \
	    src/operator/DryHeatEvent.cpp\
	    build/dep/operator/DryHeatEvent.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] DryHeatEvent'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/DryHeatEvent.cpp

-include build/operator/SaunaEvent.d
build/operator/SaunaEvent.o: \
	    src/operator/SaunaEvent.h \
	    src/operator/SaunaEvent.cpp\
	    build/dep/operator/SaunaEvent.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] SaunaEvent'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/SaunaEvent.cpp

-include build/operator/TempMEvent.d
build/operator/TempMEvent.o: \
	    src/operator/TempMEvent.h \
	    src/operator/TempMEvent.cpp\
	    build/dep/operator/TempMEvent.dep \
	    src/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.h \
	    src/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.h \
	    src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TempMEvent'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streams.cep/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/TempMEvent.cpp

-include build/operator/TempSteadyEvent.d
build/operator/TempSteadyEvent.o: \
	    src/operator/TempSteadyEvent.h \
	    src/operator/TempSteadyEvent.cpp\
	    build/dep/operator/TempSteadyEvent.dep \
	    src/type/BeJwrMUwyKy5JTUypBAATwwPI.h \
	    src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] TempSteadyEvent'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streams.cep/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/TempSteadyEvent.cpp

-include build/operator/OutputEvents.d
build/operator/OutputEvents.o: \
	    src/operator/OutputEvents.h \
	    src/operator/OutputEvents.cpp\
	    build/dep/operator/OutputEvents.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] OutputEvents'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/OutputEvents.cpp

-include build/operator/JSONOutput.d
build/operator/JSONOutput.o: \
	    src/operator/JSONOutput.h \
	    src/operator/JSONOutput.cpp\
	    build/dep/operator/JSONOutput.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] JSONOutput'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streamsx.json/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/spl/utility/JavaOp/../../../impl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/java/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/JSONOutput.cpp

-include build/operator/HttpEvents.d
build/operator/HttpEvents.o: \
	    src/operator/HttpEvents.h \
	    src/operator/HttpEvents.cpp\
	    build/dep/operator/HttpEvents.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] HttpEvents'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streamsx.inet/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/spl/utility/JavaOp/../../../impl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/java/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/HttpEvents.cpp

-include build/operator/HttpEventsDbg.d
build/operator/HttpEventsDbg.o: \
	    src/operator/HttpEventsDbg.h \
	    src/operator/HttpEventsDbg.cpp\
	    build/dep/operator/HttpEventsDbg.dep \
	    src/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] HttpEventsDbg'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/HttpEventsDbg.cpp

-include build/operator/MaxMinTemp.d
build/operator/MaxMinTemp.o: \
	    src/operator/MaxMinTemp.h \
	    src/operator/MaxMinTemp.cpp\
	    build/dep/operator/MaxMinTemp.dep \
	    src/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.h  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] MaxMinTemp'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/MaxMinTemp.cpp

-include build/operator/NewMaxMin.d
build/operator/NewMaxMin.o: \
	    src/operator/NewMaxMin.h \
	    src/operator/NewMaxMin.cpp\
	    build/dep/operator/NewMaxMin.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] NewMaxMin'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/NewMaxMin.cpp

-include build/operator/JSONTempOutput.d
build/operator/JSONTempOutput.o: \
	    src/operator/JSONTempOutput.h \
	    src/operator/JSONTempOutput.cpp\
	    build/dep/operator/JSONTempOutput.dep  \
	    build/cppOptions \
	    | build/operator
	@echo ' [CXX-operator] JSONTempOutput'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/com.ibm.streamsx.json/impl/nl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/spl/utility/JavaOp/../../../impl/include -I /opt/ibm/InfoSphere_Streams/4.3.0.0/java/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/JSONTempOutput.cpp

-include build/operator/WeatherSummary/WeatherStationReadings.d
build/operator/WeatherSummary/WeatherStationReadings.o: \
	    src/operator/WeatherSummary/WeatherStationReadings.h \
	    src/operator/WeatherSummary/WeatherStationReadings.cpp\
	    build/dep/operator/WeatherSummary/WeatherStationReadings.dep \
	    src/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.h  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.WeatherStationReadings'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/WeatherStationReadings.cpp

-include build/operator/WeatherSummary/FilteredMissingValues.d
build/operator/WeatherSummary/FilteredMissingValues.o: \
	    src/operator/WeatherSummary/FilteredMissingValues.h \
	    src/operator/WeatherSummary/FilteredMissingValues.cpp\
	    build/dep/operator/WeatherSummary/FilteredMissingValues.dep  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.FilteredMissingValues'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/FilteredMissingValues.cpp

-include build/operator/WeatherSummary/FilteredOlderValues.d
build/operator/WeatherSummary/FilteredOlderValues.o: \
	    src/operator/WeatherSummary/FilteredOlderValues.h \
	    src/operator/WeatherSummary/FilteredOlderValues.cpp\
	    build/dep/operator/WeatherSummary/FilteredOlderValues.dep  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.FilteredOlderValues'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/FilteredOlderValues.cpp

-include build/operator/WeatherSummary/NoDuplicates.d
build/operator/WeatherSummary/NoDuplicates.o: \
	    src/operator/WeatherSummary/NoDuplicates.h \
	    src/operator/WeatherSummary/NoDuplicates.cpp\
	    build/dep/operator/WeatherSummary/NoDuplicates.dep  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.NoDuplicates'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/NoDuplicates.cpp

-include build/operator/WeatherSummary/TimeFilter.d
build/operator/WeatherSummary/TimeFilter.o: \
	    src/operator/WeatherSummary/TimeFilter.h \
	    src/operator/WeatherSummary/TimeFilter.cpp\
	    build/dep/operator/WeatherSummary/TimeFilter.dep  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.TimeFilter'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/TimeFilter.cpp

-include build/operator/WeatherSummary/FilteredAndPrepared.d
build/operator/WeatherSummary/FilteredAndPrepared.o: \
	    src/operator/WeatherSummary/FilteredAndPrepared.h \
	    src/operator/WeatherSummary/FilteredAndPrepared.cpp\
	    build/dep/operator/WeatherSummary/FilteredAndPrepared.dep  \
	    build/cppOptions \
	    | build/operator/WeatherSummary
	@echo ' [CXX-operator] WeatherSummary.FilteredAndPrepared'
	@$(CXX) -o $@ -MD -I /opt/ibm/InfoSphere_Streams/4.3.0.0/toolkits/spl/impl/nl/include -DSPLJAVAFUNCTION_ADL_FILENAME=\"application.evdetect.adl\" -c $(SPL_CXXFLAGS) src/operator/WeatherSummary/FilteredAndPrepared.cpp

build/operator:
	-@mkdir -m 775 -p build/operator

build/operator/WeatherSummary:
	-@mkdir -m 775 -p build/operator/WeatherSummary

functions: $(SPL_FUNCTIONS)

sos: $(SPL_SO_BINS)

SORawObservations = \
	    build/operator/RawObservations.o \
	    build/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.o 

bin/RawObservations.so: \
	$(SORawObservations) \
	build/dep/RawObservations.so \
	build/ldOptions
	@echo ' [LD-so] so RawObservations'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/RawObservations.so -fPIC -shared $(SORawObservations) -lcurl $(SPL_LDFLAGS)

SODryHeatEvent = \
	    build/operator/DryHeatEvent.o \
	    build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/DryHeatEvent.so: \
	$(SODryHeatEvent) \
	build/dep/DryHeatEvent.so \
	build/ldOptions
	@echo ' [LD-so] so DryHeatEvent'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/DryHeatEvent.so -fPIC -shared $(SODryHeatEvent) $(SPL_LDFLAGS)

SOSaunaEvent = \
	    build/operator/SaunaEvent.o \
	    build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/SaunaEvent.so: \
	$(SOSaunaEvent) \
	build/dep/SaunaEvent.so \
	build/ldOptions
	@echo ' [LD-so] so SaunaEvent'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/SaunaEvent.so -fPIC -shared $(SOSaunaEvent) $(SPL_LDFLAGS)

SOTempMEvent = \
	    build/operator/TempMEvent.o \
	    build/type/BeJwrMU4yKcosTk0ySSnKLwCSqakFAEyGAdw.o \
	    build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/TempMEvent.so: \
	$(SOTempMEvent) \
	build/dep/TempMEvent.so \
	build/ldOptions
	@echo ' [LD-so] so TempMEvent'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TempMEvent.so -fPIC -shared $(SOTempMEvent) $(SPL_LDFLAGS)

SOTempSteadyEvent = \
	    build/operator/TempSteadyEvent.o \
	    build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
	    build/type/BeJwrMUwyKy5JTUypBAATwwPI.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/TempSteadyEvent.so: \
	$(SOTempSteadyEvent) \
	build/dep/TempSteadyEvent.so \
	build/ldOptions
	@echo ' [LD-so] so TempSteadyEvent'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/TempSteadyEvent.so -fPIC -shared $(SOTempSteadyEvent) $(SPL_LDFLAGS)

SOOutputEvents = \
	    build/operator/OutputEvents.o \
	    build/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.o \
	    build/type/BeJwdycEOgjAQhOFnqoLiWaMQjhrvNZ3iBtiS7lLi29tymeT_1Rg96EWNErVLga3DoTB0_0gph2edEMXynmxZ_1Ldnz35hQx5TehXWdypD_1fOGxLINbRNBuxa2Ed8XDDEAEZTVXwuQCu56AZjgUeq_0jeOWH1i_1i20wqRGgmsfyyODvm.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/OutputEvents.so: \
	$(SOOutputEvents) \
	build/dep/OutputEvents.so \
	build/ldOptions
	@echo ' [LD-so] so OutputEvents'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/OutputEvents.so -fPIC -shared $(SOOutputEvents) $(SPL_LDFLAGS)

SOJSONOutput = \
	    build/operator/JSONOutput.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o \
	    build/type/BeJwrMS62TC1LzSsJqSxILTY0ArODSxJLMvPzYDKZuakALW4PBP.o 

bin/JSONOutput.so: \
	$(SOJSONOutput) \
	build/dep/JSONOutput.so \
	build/ldOptions
	@echo ' [LD-so] so JSONOutput'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/JSONOutput.so -fPIC -shared $(SOJSONOutput) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOHttpEvents = \
	    build/operator/HttpEvents.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o 

bin/HttpEvents.so: \
	$(SOHttpEvents) \
	build/dep/HttpEvents.so \
	build/ldOptions
	@echo ' [LD-so] so HttpEvents'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/HttpEvents.so -fPIC -shared $(SOHttpEvents) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOHttpEventsDbg = \
	    build/operator/HttpEventsDbg.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o \
	    build/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.o 

bin/HttpEventsDbg.so: \
	$(SOHttpEventsDbg) \
	build/dep/HttpEventsDbg.so \
	build/ldOptions
	@echo ' [LD-so] so HttpEventsDbg'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/HttpEventsDbg.so -fPIC -shared $(SOHttpEventsDbg) $(SPL_LDFLAGS)

SOMaxMinTemp = \
	    build/operator/MaxMinTemp.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o \
	    build/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.o 

bin/MaxMinTemp.so: \
	$(SOMaxMinTemp) \
	build/dep/MaxMinTemp.so \
	build/ldOptions
	@echo ' [LD-so] so MaxMinTemp'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/MaxMinTemp.so -fPIC -shared $(SOMaxMinTemp) -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SONewMaxMin = \
	    build/operator/NewMaxMin.o \
	    build/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.o \
	    build/type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.o 

bin/NewMaxMin.so: \
	$(SONewMaxMin) \
	build/dep/NewMaxMin.so \
	build/ldOptions
	@echo ' [LD-so] so NewMaxMin'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/NewMaxMin.so -fPIC -shared $(SONewMaxMin) $(SPL_LDFLAGS)

SOJSONTempOutput = \
	    build/operator/JSONTempOutput.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o \
	    build/type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.o 

bin/JSONTempOutput.so: \
	$(SOJSONTempOutput) \
	build/dep/JSONTempOutput.so \
	build/ldOptions
	@echo ' [LD-so] so JSONTempOutput'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/JSONTempOutput.so -fPIC -shared $(SOJSONTempOutput) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOHttpTempEvents = \
	    build/operator/HttpEvents.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o 

bin/HttpTempEvents.so: \
	$(SOHttpTempEvents) \
	build/dep/HttpTempEvents.so \
	build/ldOptions
	@echo ' [LD-so] so HttpTempEvents'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/HttpTempEvents.so -fPIC -shared $(SOHttpTempEvents) -lstreams-stdtk-javaop -L /opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -Wl,-rpath -Wl,/opt/ibm/InfoSphere_Streams/4.3.0.0/java/jre/lib/amd64/j9vm -lpthread -ldl -lstreams-stdtk-runtime $(SPL_LDFLAGS)

SOHttpTempEventsDbg = \
	    build/operator/HttpEventsDbg.o \
	    build/type/BeJwrMSw2NMgqzs8LLinKzEsHACrhAWr.o \
	    build/type/BeJyrNIo3NArPzEvJL_1dNLMpOLTI0dMvMS8yBcACkegr2.o 

bin/HttpTempEventsDbg.so: \
	$(SOHttpTempEventsDbg) \
	build/dep/HttpTempEventsDbg.so \
	build/ldOptions
	@echo ' [LD-so] so HttpTempEventsDbg'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/HttpTempEventsDbg.so -fPIC -shared $(SOHttpTempEventsDbg) $(SPL_LDFLAGS)

SOWeatherSummary.WeatherStationReadings = \
	    build/operator/WeatherSummary/WeatherStationReadings.o \
	    build/type/BeJyrNI83NIkEAl9fF5eMjNzc4mJDSxA_13tc33sUlPiMjPjc3HiQI4YOlEIJAEaA4iqCRMRbtQDLXyBiLERAJLMaAJADJ9TeQ.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o \
	    build/type/BeJwrMSw2NClKLPdPKk4tKkssyczPAwBFJwdU.o 

bin/WeatherSummary.WeatherStationReadings.so: \
	$(SOWeatherSummary.WeatherStationReadings) \
	build/dep/WeatherSummary.WeatherStationReadings.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.WeatherStationReadings'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.WeatherStationReadings.so -fPIC -shared $(SOWeatherSummary.WeatherStationReadings) $(SPL_LDFLAGS)

SOWeatherSummary.FilteredMissingValues = \
	    build/operator/WeatherSummary/FilteredMissingValues.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o 

bin/WeatherSummary.FilteredMissingValues.so: \
	$(SOWeatherSummary.FilteredMissingValues) \
	build/dep/WeatherSummary.FilteredMissingValues.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.FilteredMissingValues'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.FilteredMissingValues.so -fPIC -shared $(SOWeatherSummary.FilteredMissingValues) $(SPL_LDFLAGS)

SOWeatherSummary.FilteredOlderValues = \
	    build/operator/WeatherSummary/FilteredOlderValues.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o 

bin/WeatherSummary.FilteredOlderValues.so: \
	$(SOWeatherSummary.FilteredOlderValues) \
	build/dep/WeatherSummary.FilteredOlderValues.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.FilteredOlderValues'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.FilteredOlderValues.so -fPIC -shared $(SOWeatherSummary.FilteredOlderValues) $(SPL_LDFLAGS)

SOWeatherSummary.NoDuplicates = \
	    build/operator/WeatherSummary/NoDuplicates.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o 

bin/WeatherSummary.NoDuplicates.so: \
	$(SOWeatherSummary.NoDuplicates) \
	build/dep/WeatherSummary.NoDuplicates.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.NoDuplicates'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.NoDuplicates.so -fPIC -shared $(SOWeatherSummary.NoDuplicates) $(SPL_LDFLAGS)

SOWeatherSummary.TimeFilter = \
	    build/operator/WeatherSummary/TimeFilter.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o 

bin/WeatherSummary.TimeFilter.so: \
	$(SOWeatherSummary.TimeFilter) \
	build/dep/WeatherSummary.TimeFilter.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.TimeFilter'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.TimeFilter.so -fPIC -shared $(SOWeatherSummary.TimeFilter) $(SPL_LDFLAGS)

SOWeatherSummary.FilteredAndPrepared = \
	    build/operator/WeatherSummary/FilteredAndPrepared.o \
	    build/type/BeJwdyEEOgkAMBdAzNWKcvSRojCu9wJB_0SANMJ22R6wss34vkRB45RMtdGU_06au_0w3zlfWTA0gaUOibFVlRIT3arBfTW8ZZ6lz_0YTpU0KP5BZythiNGDP5shPBfhVNPa4HNGtHqf_1l9IvDW.o \
	    build/type/BeJwdyVEOgkAMhOEzNaLis0YhPuoFMJ0lDW672S0Qby_1LyyT_1N34pRMUHF9OrMXo62qcgL7u8JSI0jpjCuW6v90CnjO_12LujmKCz_0Cy1jTSbqE7WrKHcYWHS8YcxAmaip_0EoAP9V8g0OFx1x87z8NqjKy.o 

bin/WeatherSummary.FilteredAndPrepared.so: \
	$(SOWeatherSummary.FilteredAndPrepared) \
	build/dep/WeatherSummary.FilteredAndPrepared.so \
	build/ldOptions
	@echo ' [LD-so] so WeatherSummary.FilteredAndPrepared'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/WeatherSummary.FilteredAndPrepared.so -fPIC -shared $(SOWeatherSummary.FilteredAndPrepared) $(SPL_LDFLAGS)

standalone: bin/standalone.exe

build/standalone/standalone.o: \
	    src/standalone/standalone.h \
	    src/standalone/standalone.cpp  \
	    build/cppOptions \
	    | build/standalone
	@echo ' [CXX-standalone] standalone'
	@$(CXX) -o $@ -c $(SPL_CXXFLAGS) src/standalone/standalone.cpp

bin/standalone.exe: build/standalone/standalone.o build/ldOptions
	@echo ' [LD-standalone] standalone'
	@$(CXX_LN) $(SPL_CXXFLAGS) -o bin/standalone.exe build/standalone/standalone.o $(SO_STAND_LIB)
	@echo ' [LN-standalone] standalone '
	@ln -sf standalone bin/application.evdetect
build/standalone:
	-@mkdir -m 775 build/standalone

sablink:

	@ln -sf ../application.evdetect.sab bin/sab

bundle: application.evdetect.sab

-include build/dep/application.evdetect.sab.d
application.evdetect.sab: $(SPL_SO_BINS) $(SPL_ADL_FILE) build/dep/application.evdetect.sab.d bin/standalone.exe
	@echo ' [Bundle] application.evdetect.sab'
	@$(SPL_BUNDLE_BUILDER) $(SPL_OUTPUT_DIR_ROOT) $(SPL_OUTPUT_DIR) $(SPL_ADL_FILE) application.evdetect.sab

