#ifndef _DEFINE_H_
#define _DEFINE_H_
#include "ace/OS_NS_string.h"
#include "ace/OS_main.h"
#include "ace/Log_Msg.h"
#include "ace/Process_Manager.h"
#include "ace/Service_Config.h" 
#include <ace/Configuration.h>
#include <ace/Configuration_Import_Export.h> 
#include <ace/MMAP_Memory_Pool.h>
#include <ace/Malloc_T.h>
#include <ace/PI_Malloc.h>
#include <ace/Process_Mutex.h>
#include <ace/Based_Pointer_T.h>

#include "ace/svc_export.h"

#ifndef _CONFIG_ALLOCATOR_
typedef ACE_Allocator_Adapter<ACE_Malloc_T <ACE_MMAP_MEMORY_POOL,
                                            ACE_Process_Mutex,
                                            ACE_Control_Block>
                             > _CONFIG_ALLOCATOR_;
#endif //_CONFIG_ALLOCATOR__
#ifndef _MAX_MEM_SIZE_//�ļ���С
#define _MAX_MEM_SIZE_	4096
#endif 
#ifndef FMT_ERROR
#define FMT_ERROR		ACE_TEXT("ERROR:%D ")
#endif 


_CONFIG_ALLOCATOR_     * allocator_;
BOOL  haveCreate_;

class  CONFIG
{
public:
	CONFIG(){

	};
	~CONFIG(){};
public:

	int   HeadPicHight;         //ͷ����Ƭ�߶� ��λ������
	int   HeadPicWidth;         //ͷ����Ƭ�� 
	int   FingerPicHight;       //ָ��ͼ��߶�
	int   FingerPicWidth;       //ָ��ͼ���
    int   CollectFingerNum;     //ָ�Ʋɼ���ָ��Ŀ
	int   CollectTimes;         //ÿ��ָ�Ʋɼ��Ĵ���
	int   FemalFingerPicSize;   //Ů��ָ�Ʋɼ����
	int   MaleFingerPicSize;    //����ָ�Ʋɼ����
	int   FlyValue ;            //ͼƬ�����ȵĸ���Ҷֵ
	char  WebServiceAddr[128];  //ָ�Ʋɼ����صĵ�ַ
	char  SearchAddr[128];      //
	char  HitAddr[128];         //�����ṩ�������ϴ���ַ
	char  UpLoadPath[128];      //�����ϴ�·��
	char  FtpUser[64];          //ftp�û���
	char  FtpPassWord[64];      //ftp����
	char  FtpAddr[64];          //ftp������ip��ַ
	int   FtpPor;               //ftp�˿�
	char  FtpRemoteAddr[64];    //ftpԶ��·��
public:
	void Init()
	{
		HeadPicHight = 386;
		HeadPicWidth = 303;
		FingerPicHight = 288;
		FingerPicWidth = 256;
		CollectFingerNum = 4;
		CollectTimes = 2;
		FemalFingerPicSize  = 60;
		MaleFingerPicSize = 75;
		FlyValue = 10000;
		memset(WebServiceAddr,0x0,sizeof(WebServiceAddr));
		ACE_OS::sprintf(WebServiceAddr,"%s","http://192.168.7.219:7001/si_websvc/PageBean?WSDL");
		memset(SearchAddr,0x0,sizeof(SearchAddr));
		ACE_OS::sprintf(SearchAddr,"%s","http://192.168.3.122:7001/si/xnb/index.jsp");
		memset(HitAddr,0x0,sizeof(HitAddr));
		ACE_OS::sprintf(HitAddr,"%s","http://192.168.7.224:8088/siw/services/doSaveInfo?wsdl");
		memset(UpLoadPath,0x0,sizeof(UpLoadPath));
		ACE_OS::sprintf(UpLoadPath,"%s","F:\\��Ƶ�ɼ�\\Finger\\Finger\\UpLoad\\");
		memset(FtpUser,0x0,sizeof(FtpUser));
		ACE_OS::sprintf(FtpUser,"%s","jx");
		memset(FtpPassWord,0x0,sizeof(FtpPassWord));
		ACE_OS::sprintf(FtpPassWord,"%s","jx");
		memset(FtpAddr,0x0,sizeof(FtpAddr));
		ACE_OS::sprintf(FtpAddr,"%s","127.0.0.1");
		memset(FtpRemoteAddr,0x0,sizeof(FtpRemoteAddr));
		ACE_OS::sprintf(FtpRemoteAddr,"%s","/");
		FtpPor = 21;
	};
   
};
#endif


