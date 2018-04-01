#include <Windows.h>
#include "servicehelper.h"
#include <iostream>


#define SERVICE_NAME			L"WinServ"
#define SERVICE_DISPLAY_NAME	L"winServ"
#define SERVICE_STARTUP_TYPE	SERVICE_DEMAND_START
#define SERVICE_DEPENDENCIES	L""
#define SERVICE_ACCOUNT			L"NT AUTHORITY\\LocalService"
#define SERVICE_PASSWORD		NULL


int wmain(int argc, wchar_t *argv[]) {
	std::cout << "    sleeping for debuger attachment" << std::endl;
	Sleep(10000);
	if (argc > 1 && (*argv[1] == L'-' || *argv[1] == L'/')) {
		if (_wcsicmp(L"install", argv[1] + 1) == 0) {
			InstallService( SERVICE_NAME, SERVICE_DISPLAY_NAME,
							SERVICE_STARTUP_TYPE,
							SERVICE_DEPENDENCIES,
							SERVICE_ACCOUNT,
							SERVICE_PASSWORD );
		}
		else if (_wcsicmp(L"remove", argv[1] + 1) == 0) {
			UninstallService( SERVICE_NAME );
		}
		else {
			wsprintf(L"valid Parameters:\n",L" ");
			wsprintf(L" -install to install the service\n",L" ");
			wsprintf(L" -remove to remove the service\n",L" ");
		}
	}
	else {
			// to run -- to be done later
	}
	return 0;
}