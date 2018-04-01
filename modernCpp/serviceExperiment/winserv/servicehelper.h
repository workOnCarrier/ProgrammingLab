#pragma once

#include <Windows.h>


void InstallService(PWSTR pszServiceName,
					PWSTR pszDisplayName,
					DWORD dwStartType,
					PWSTR pszDependencies,
					PWSTR pszAccount,
					PWSTR pszpassword );
void UninstallService(PWSTR pszServiceName);
