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
#ifndef _MAX_MEM_SIZE_//文件大小
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

	int   HeadPicHight;         //头像照片高度 单位：像素
	int   HeadPicWidth;         //头像照片宽 
	int   FingerPicHight;       //指纹图像高度
	int   FingerPicWidth;       //指纹图像宽
    int   CollectFingerNum;     //指纹采集手指数目
	int   CollectTimes;         //每个指纹采集的次数
	int   FemalFingerPicSize;   //女性指纹采集面积
	int   MaleFingerPicSize;    //男性指纹采集面积
	int   FlyValue ;            //图片清晰度的傅里叶值
	char  WebServiceAddr[128];  //指纹采集下载的地址
	char  SearchAddr[128];      //
	char  HitAddr[128];         //工大提供的数据上传地址
	char  UpLoadPath[128];      //数据上传路径
	char  FtpUser[64];          //ftp用户名
	char  FtpPassWord[64];      //ftp密码
	char  FtpAddr[64];          //ftp服务器ip地址
	int   FtpPor;               //ftp端口
	char  FtpRemoteAddr[64];    //ftp远程路径
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
		ACE_OS::sprintf(UpLoadPath,"%s","F:\\视频采集\\Finger\\Finger\\UpLoad\\");
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


