#ifndef UNZIPIFY_HPP
#define UNZIPIFY_HPP

struct Unzipify
{
public:
    R_codes   _codes; // codes like ("2001" - > "k") "2" is required
    std::string                             _in_file_name;
    std::string                             _out_file_name;

public:
    void readNameData();
    Unzipify(const std::string& infile);
    ~Unzipify();
};

#endif /* UNZIPIFY_HPP */
