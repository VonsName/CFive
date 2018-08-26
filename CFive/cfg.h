#pragma once

int writeCfg(const char *fileName, const  char *key, const char *value);

int getCfg(const char *fileName, const char *key, char **value);
