#include <SRM.h>
#include <json_pack.h>

#ifndef SRM_JSON
#define SRM_JSON

#ifdef __cplusplus
extern "C" {
#endif

JSON_OBJECT SRM_toJSON(SRM *srmp,JSON_OBJECT json,const char *choose);
int SRM_fromJSON(SRM *srmp,JSON_OBJECT json);
/* ��src�е�ͬ����Ա������desc,��ʽ�Զ�ת�� */
int SRM_copy(SRM *desc,SRM *src,const char *choose);

//����JSONģ�幹��srm,�ɹ�����0
int SRM_tpl(SRM *srmp,JSON_OBJECT tpl_json);
//��ģ��⹹��srm,�ɹ�����0
int SRM_mk(SRM *srmp,const char *tabname);

#ifdef __cplusplus
}
#endif

#endif
