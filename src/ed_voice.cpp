#include "ed_voice.h"
#include "SoraVoice.h"
#include "InitParam.h"
#include "Log.h"

SVDECL void SVCALL Init(void *p)
{
	LOG_OPEN;
	InitParam* ip = (InitParam*)p;
	if (!ip || ip->sv) return;

	if (InitAddrs(ip)) {
		ip->sv = SoraVoice::CreateInstance(ip);
	}
}

SVDECL void SVCALL End(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || !ip->sv) return;

	SoraVoice::DestoryInstance((SoraVoice*)ip->sv);
	ip->sv = nullptr;
	LOG_CLOSE;
}

SVDECL void SVCALL Play(void *v, void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!v || !p || !ip->sv) return;

	((SoraVoice*)ip->sv)->Play((const char*)v);
}

SVDECL void SVCALL Stop(void *p)
{
	InitParam* ip = (InitParam*)p;
	if (!ip || !ip->sv) return;

	((SoraVoice *)ip->sv)->Stop();
}


