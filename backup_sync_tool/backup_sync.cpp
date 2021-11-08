#include "fileops_lib.cpp"
#include<fts.h>
struct t_node
{
    char path[PATH_MAX]; //full path , max length is 4096
    char name[NAME_MAX]; //base name , max length is 255
    bool isdir;          //is directory or not
    struct stat st_buf;
    size_t n_files;
    struct t_node **child;
};
class tree
{
private:
    struct t_node *root;
public:
    //initialsing tree
    void create_tree(char *dir_name)
    {
        struct t_node *node = new struct t_node;
        realpath(dir_name, node->path);
        snprintf(node->name, NAME_MAX, "%s", basename(node->path));
        node->isdir = true;
       
        
        DIR *dir = opendir(node->path);
        if (dir == NULL)
        {
            struct dirent *entry;
        }

        int status = stat(node->path, &(node->st_buf));
        if (status != 0)
        {
            std::cerr << CMD_NAME << ": connot stat '" << node->path << "': " << strerror(errno) << '\n';
            return;
        }
        else if (S_ISREG(node->st_buf.st_mode))
        {

            return;
        }
        else if (S_ISDIR(node->st_buf.st_mode))
        {   

        }
    }
    int recursive_delete(const char *dir)
{
    int ret = 0;
    FTS *ftsp = NULL;
    FTSENT *curr;

    // Cast needed (in C) because fts_open() takes a "char * const *", instead
    // of a "const char * const *", which is only allowed in C++. fts_open()
    // does not modify the argument.
    char *files[] = { (char *) dir, NULL };

    // FTS_NOCHDIR  - Avoid changing cwd, which could cause unexpected behavior
    //                in multithreaded programs
    // FTS_PHYSICAL - Don't follow symlinks. Prevents deletion of files outside
    //                of the specified directory
    // FTS_XDEV     - Don't cross filesystem boundaries
    ftsp = fts_open(files, FTS_NOCHDIR | FTS_PHYSICAL | FTS_XDEV, NULL);
    if (!ftsp) {
        fprintf(stderr, "%s: fts_open failed: %s\n", dir, strerror(errno));
        ret = -1;
        goto finish;
    }

    while ((curr = fts_read(ftsp))) {
        switch (curr->fts_info) {
        case FTS_NS:
        case FTS_DNR:
        case FTS_ERR:
            fprintf(stderr, "%s: fts_read error: %s\n",
                    curr->fts_accpath, strerror(curr->fts_errno));
            break;

        case FTS_DC:
        case FTS_DOT:
        case FTS_NSOK:
            // Not reached unless FTS_LOGICAL, FTS_SEEDOT, or FTS_NOSTAT were
            // passed to fts_open()
            break;

        case FTS_D:
            // Do nothing. Need depth-first search, so directories are deleted
            // in FTS_DP
            break;

        case FTS_DP:
        case FTS_F:
        case FTS_SL:
        case FTS_SLNONE:
        case FTS_DEFAULT:
            if (remove(curr->fts_accpath) < 0) {
                fprintf(stderr, "%s: Failed to remove: %s\n",
                        curr->fts_path, strerror(curr->fts_errno));
                ret = -1;
            }
            break;
        }
    }

finish:
    if (ftsp) {
        fts_close(ftsp);
    }

    return ret;
}
};
struct something
{
    char str[4096];
};
int main()
{
    // int status = mkdir("/hello", 0664);
    //   std::cout << status << std::endl;
    tree t1;
    t1.create_tree_init("hello");
    std::string str;
    char str1[4096];
    std::cout << "size of is " << sizeof(struct t_node);
    //char * we are passing should not be null or garbage, means it should have allocated memory
    realpath("/home/linuxfreak/lib", str1);

    std::cout << str1;
    str.assign(str1);
    int status1;
    // try
    // {

    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // catch (...)
    // {
    //     std::cout << "error occured";
    // }
    status1 = isFile(str);
    std::cout << "\n"
              << str;
    std::cout << status1 << " status";
    //
}
