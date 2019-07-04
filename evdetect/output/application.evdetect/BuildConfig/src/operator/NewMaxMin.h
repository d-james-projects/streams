// eJy1VNFymkAUnX31K3YyeYCZVFaSOB3TdoZim0HR0IDp6EsGdYM7yoLsKorx37sQNAHJ9CHt8gAc9tx77tl7YeGivuJkQfi21dJXjAc_0aAAkLhWc1esK34ZY_0Y47cdSzVdXRG2Zis87S3hiOY1mOGxv2BPFue4i8cVe3Nx2zt7YSr90dYUcb6RpbarF2Pbqfo_1rsrBxxwJIEqUz_1Qfum7al943brzZltJ2byOYn75lDTHxtz_0nM5eFgMjdtfSX8zCCyzZ3VmW13jHfx7iH1qaM1oOG_0HaQIVMO5yfD5ZRRGmvOdugG2ZrdbTInD5pVp8aQBR9nmZQuhfKZfgKrujl48R4xGhHsiwxgu2IjTdn2coxMhDFDGgzAIfKyISdn3mTn1ClTiI5ix0J1jB6ynmeMKVqctdQAOK0xNKz4mEQXQU8j9cBT6Isn7Y1aBY5AlKkpRnrXuYP_1ruxsF_0KMnwGyybL8PnZ1jcTWi_0_0wss_0y7LMsySpGt3fEpXOTD8Cis13BRYUjkD_1AQrxZR40wDu4BtHP9j5kIskQvG_1iyhl3XdR7UElbAsnSEBPvh4cqISPJPkGstXYJxxKaS0XMOt0ge5hPCMLLKE3Du5r_0xoATZBnBoceLyoBh6kR8N2Y4WidwQ7xMRCz07wCuYhXfkHUK5_1Qan46HsHpeHzQ_0mwergFei45yxK_1sqAOdFIzeKxmd1Ibeqw6JKv4AsbfMAe


#ifndef SPL_OPER_INSTANCE_NEWMAXMIN_H_
#define SPL_OPER_INSTANCE_NEWMAXMIN_H_

#include <SPL/Runtime/Serialization/NetworkByteBuffer.h>
#include <SPL/Runtime/Operator/Operator.h>
#include <SPL/Runtime/Operator/ParameterValue.h>
#include <SPL/Runtime/Operator/OperatorContext.h>
#include <SPL/Runtime/Operator/OperatorMetrics.h>
#include <SPL/Runtime/Operator/Port/AutoPortMutex.h>
#include <SPL/Runtime/Operator/State/StateHandler.h>
#include <SPL/Runtime/ProcessingElement/PE.h>
#include <SPL/Runtime/Type/SPLType.h>
#include <SPL/Runtime/Utility/CV.h>
using namespace UTILS_NAMESPACE;

#include "../type/BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0.h"
#include "../type/BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp.h"

#include <bitset>

#define MY_OPERATOR NewMaxMin$OP
#define MY_BASE_OPERATOR NewMaxMin_Base
#define MY_OPERATOR_SCOPE SPL::_Operator

namespace SPL {
namespace _Operator {

class MY_BASE_OPERATOR : public Operator
{
public:
    
    typedef SPL::BeJwrMUszz02sCEnNLSg2NIGygksSSzLz8zwNLYAC_1knFqUVlYIGQzNxUoPLMPJhyCAtJeWYemnIA6rYkDp IPort0Type;
    typedef SPL::BeJwrMS22TC1LzSsJqSxITTPPTawISc0tKDY0gbKCSxJLMvPzgDKZeTAZCAsqAwA5ZRk0 OPort0Type;
    
    MY_BASE_OPERATOR();
    
    ~MY_BASE_OPERATOR();
    
    inline void tupleLogic(Tuple & tuple, uint32_t port);
    void processRaw(Tuple & tuple, uint32_t port);
    
    inline void punctLogic(Punctuation const & punct, uint32_t port);
    void processRaw(Punctuation const & punct, uint32_t port);
    void punctPermitProcessRaw(Punctuation const & punct, uint32_t port);
    void punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port);
    
    inline void submit(Tuple & tuple, uint32_t port)
    {
        Operator::submit(tuple, port);
    }
    inline void submit(Punctuation const & punct, uint32_t port)
    {
        Operator::submit(punct, port);
    }
    
    
    
    SPL::rstring lit$0;
    SPL::uint32 lit$1;
    SPL::float32 lit$2;
    SPL::float32 lit$3;
    
    SPL::float32 state$currentMax;
    SPL::float32 state$currentMin;
    
protected:
    Mutex $svMutex;
    typedef std::bitset<2> OPortBitsetType;
    OPortBitsetType $oportBitset;
    Mutex $fpMutex;
    void checkpointStateVariables(NetworkByteBuffer & opstate) const;
    void restoreStateVariables(NetworkByteBuffer & opstate);
    void checkpointStateVariables(Checkpoint & ckpt);
    void resetStateVariables(Checkpoint & ckpt);
    void resetStateVariablesToInitialState();
    bool hasStateVariables() const;
    void resetToInitialStateRaw();
    void checkpointRaw(Checkpoint & ckpt);
    void resetRaw(Checkpoint & ckpt);

private:
    static bool globalInit_;
    static bool globalIniter();
    ParameterMapType paramValues_;
    ParameterMapType& getParameters() { return paramValues_;}
    void addParameterValue(std::string const & param, ConstValueHandle const& value)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create(value));
    }
    void addParameterValue(std::string const & param)
    {
        ParameterMapType::iterator it = paramValues_.find(param);
        if (it == paramValues_.end())
            it = paramValues_.insert (std::make_pair (param, ParameterValueListType())).first;
        it->second.push_back(&ParameterValue::create());
    }
};


class MY_OPERATOR : public MY_BASE_OPERATOR
    
{
public:
   
       void getCheckpoint(NetworkByteBuffer & opstate) { checkpointStateVariables(opstate); }
       void restoreCheckpoint(NetworkByteBuffer & opstate) { restoreStateVariables(opstate); }
   
   
};

} // namespace _Operator
} // namespace SPL

#undef MY_OPERATOR_SCOPE
#undef MY_BASE_OPERATOR
#undef MY_OPERATOR
#endif // SPL_OPER_INSTANCE_NEWMAXMIN_H_

