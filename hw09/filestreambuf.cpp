#include "filestreambuf.h"

FileStreamBuf::FileStreamBuf(FILE* fp) : fp(fp) {
	resetSuperOPtrs();
}
FileStreamBuf::~FileStreamBuf() {
	delete[] buf;
	buf = nullptr;
	fclose(fp);
	fp = nullptr;
}

void FileStreamBuf::resetSuperOPtrs() {
	setp(buf, buf + len);
}

void FileStreamBuf::resetSuperIPtrs() {
	setg(buf, buf + len, buf + len);
}

int FileStreamBuf::overflow(int c) {
	fwrite(buf, sizeof(char), len, fp);
	buf[0] = (char) c;
	setp(buf + 1, buf + len);
	return c;
}

int FileStreamBuf::underflow() {
	fread(buf, sizeof(char), len, fp);
	setg(buf, buf + len, buf + len);
	return buf[len];
}

int FileStreamBuf::uflow() {
	fread(buf, sizeof(char), len, fp);
	setg(buf, buf + len - 1, buf + len);
	return buf[len];
}

int FileStreamBuf::sync() {
	if (!fwrite(buf, sizeof(char), pptr()-buf, fp))
		return -1;
	resetSuperOPtrs();
	return 0;
}
