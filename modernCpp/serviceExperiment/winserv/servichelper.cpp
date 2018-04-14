
#include <iostream>
#include <Windows.h>
#include "servicehelper.h"
#include "myException.h"
#include <memory>

	class scMgrDel{
		SC_HANDLE& m_val;
	public: scMgrDel(SC_HANDLE& val) :m_val(val) {}
			auto operator()(SC_HANDLE__**)->void {
				CloseServiceHandle(m_val);
				m_val = NULL;
			}
	};

void InstallService(PWSTR pszServiceName, PWSTR pszDisplayName,
	DWORD dwStartType, PWSTR pszDependencies,
	PWSTR pszAccount, PWSTR pszpassword) {

	wchar_t szPath[MAX_PATH];
	SC_HANDLE	schSCManager = NULL;
	SC_HANDLE	schService = NULL;

	try {
		if (GetModuleFileName(NULL, szPath, ARRAYSIZE(szPath)) == 0) {
			throw myException("GetModuleFileName failed w/ err 0x%08lx\n", GetLastError());
		}
	}
	catch (myException& e) {
		std::cout << __FUNCTION__ << e.what() << std::endl;
		throw;
	}
	// open service control manager db
	try {
		scMgrDel	deleter(schSCManager);
		schSCManager = OpenSCManager(NULL, NULL,
			SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE);
		if (NULL == schSCManager) {
			wprintf (L"OpenSCManager failed w/err 0x%08lx\n", GetLastError());
			throw myException("OpenSCManager failed \n" );
		}
		else {
			std::unique_ptr<SC_HANDLE, scMgrDel> local_ptr(&schSCManager, deleter);
			// scMgr.reset( &schSCManager);
			schService = CreateService(*local_ptr, pszServiceName, pszDisplayName,
				SERVICE_QUERY_STATUS,
				SERVICE_WIN32_OWN_PROCESS,
				dwStartType,
				SERVICE_ERROR_NORMAL,
				szPath, NULL, NULL,
				pszDependencies, pszAccount, pszpassword);
			if (schService == NULL) {
				wprintf (L"Create service failed w/err 0x%08lx\n", GetLastError());
				throw myException("Create service failed \n" );
			}
			wprintf(L"service is installed\n");
		}
	}
	catch (myException & e) {
		std::cout << __FUNCTION__ << e.what() << std::endl;
		throw;
	}
	// 

}
void UninstallService(PWSTR pszServiceName) {
	SC_HANDLE	schSCManager = NULL;
	SC_HANDLE	schService = NULL;
	scMgrDel	mgrDeleter(schSCManager);
	SERVICE_STATUS	svcStatus = {};

	schSCManager = OpenSCManager(NULL, NULL,
		SC_MANAGER_CONNECT | SC_MANAGER_CREATE_SERVICE);
	if (NULL == schSCManager) {
		wprintf (L"OpenSCManager failed w/err 0x%08lx\n", GetLastError());
		throw myException("OpenSCManager failed \n" );
	}
	std::unique_ptr<SC_HANDLE, scMgrDel> scMgrPtr(&schSCManager, mgrDeleter);
	// scMgr.reset( &schSCManager);
	schService = OpenService( *scMgrPtr,pszServiceName, SERVICE_STOP | 
			SERVICE_QUERY_STATUS | DELETE);
	if (schService == NULL) {
		wprintf (L"Open service failed w/err 0x%08lx\n", GetLastError());
		throw myException("Open service failed \n" );
	}
	scMgrDel	svcDeleter(schService);
	std::unique_ptr<SC_HANDLE, scMgrDel> svcPtr(&schService , svcDeleter);
	QueryServiceStatus(*svcPtr, &svcStatus);
	if (svcStatus.dwCurrentState != SERVICE_STOPPED)
	if (ControlService(*svcPtr, SERVICE_CONTROL_STOP, &svcStatus)) {
		wprintf(L"Stopping %s.", pszServiceName);
		Sleep(1000);

		while (QueryServiceStatus(*svcPtr, &svcStatus)) {
			if (svcStatus.dwCurrentState == SERVICE_STOP_PENDING) {
				wprintf(L".");
				Sleep(1000);
			}
			else break;
		}
	}else{
		auto errCode = GetLastError();
		wprintf (L"could not send control code to service w/err 0x%08lx\n", errCode );
		throw myException("Open service failed \n", errCode );
	}
	if (svcStatus.dwCurrentState != SERVICE_STOPPED) {
		auto errCode = GetLastError();
		wprintf (L"service could not be stopped w/err 0x%08lx\n", errCode );
		throw myException("service could not be stopped\n", errCode );
	}
	if (!DeleteService(*svcPtr)) {
		auto errCode = GetLastError();
		wprintf (L"service could not be stopped w/err 0x%08lx\n", errCode );
		throw myException("service could not be stopped\n", errCode );
	}
	wprintf(L"service deleted ");
}
