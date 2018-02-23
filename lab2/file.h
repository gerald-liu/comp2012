#ifndef FILE_H
#define FILE_H

class File
{
public:
	File();
	~File();
	File(const File &file);
	File(const char *name);

	bool equals(const File &file) const;
	void print() const;

private:
	char *name;
};

#endif