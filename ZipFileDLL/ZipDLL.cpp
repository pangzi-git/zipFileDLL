#include "ace/svc_export.h"
#include <iostream>
#include <ace/DLL.h>
#include "cUnpackFile.h"
#include "cPackFile.h"

#pragma comment(lib, "zlib\\zdll.lib")// you can import file zlib.cpp in the project instead of load zdll.lib.

#include <string>
#include "Interface.h"
using namespace std;

CLogInterface *pstrLog=NULL;

extern "C" ACE_Svc_Export int Zip(void * pLog,const char *LocalPath ,const char * pFileName);
int Zip(void * pLog,const char *LocalPath ,const char * pFileName)
{
	cPackFile packTool;
	int ret = -1;
	char szFileName[512]={0x0};
	char szZipFileName[512]={0x0};
	sprintf(szFileName,"%s%s",LocalPath,pFileName);
	sprintf(szZipFileName,"%s.zip",szFileName);
	ret = packTool.CreateZipFromDir(szFileName,szZipFileName);
	return ret;
	/*HZIP hz; 
	bool p_abort=false;
	ZRESULT zr;    //操作返回值 
	try
	{
		if(pLog ==0x0) return FALSE;
		pstrLog = (CLogInterface *)pLog;
		string zipFileName= LocalPath+string(pFileName)+string(".zip");
		hz=CreateZip(zipFileName.c_str(),0);
		if (hz==0)
		{
			pstrLog->LOG(1,"* Failed to create file.zip");
		}
		string FileFullName =LocalPath+string(pFileName);
		zr=ZipAdd(hz,pFileName,FileFullName.c_str()); 
		if (zr!=ZR_OK) 
			pstrLog->LOG(1,"* Failed to add 120k");
		zr=CloseZip(hz); 
		if (zr!=ZR_OK)
			pstrLog->LOG(1,"* Failed to close file.zip");
		p_abort = true;
	}
	catch(...)
	{
		pstrLog->LOG(0,"调用Zip函数发生异常");
	}
	return p_abort;*/
};
extern "C" ACE_Svc_Export int UnZip(void * pLog,const char *LocalPath ,const char * pFileName);
int UnZip(void * pLog,const char *LocalPath ,const char * pFileName)
{
	cUnpackFile unpackTool;
	int ret = -1;
	char szFileName[512]={0x0};
	char szUnZipFileName[512]={0x0};
	sprintf(szFileName,"%s%s",LocalPath,pFileName);
	sprintf(szUnZipFileName,"%s.zip",szFileName);
	ret = unpackTool.CreateDirFromZip(szFileName,szUnZipFileName);
	return ret;
	/*HZIP hz; 
	bool p_abort=false;
	ZRESULT zr;    //操作返回值 
	try
	{
		char strFileName[256]={0x0};
		strncpy(strFileName,pFileName,strlen(pFileName)-4);
		string unzipFileName;
		string zipFileName= string(LocalPath)+string(pFileName);
		unzipFileName = string(LocalPath)+string(strFileName);
		hz=OpenZip(zipFileName.c_str(),0); 
		if (hz==0) printf("* Failed to open file.zip");
		zr=UnzipItem(hz,0,unzipFileName.c_str()); 
		if (zr!=ZR_OK) printf("* Failed to unzip file.big");
		zr=CloseZip(hz); if (zr!=ZR_OK) printf("* Failed to close file.zip");
		p_abort = true;
	}
	catch(...)
	{
	}
	return p_abort;
	*/
};