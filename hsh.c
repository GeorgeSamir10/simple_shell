/**
* hsh - main shell loop
* @info: parameter & return info struct
* @av: argument vector from main()

* Return: 0 on success, 1 on error
*/

int hsh(info_t *info, char **av)
{
    ssize_t r = 0;
    int builtin_rec = 0;

    while (r != -1 && builtin_rec != -2)
    {
        clear_info(info);
        if (interactive(info))
            _puts("$ ");
        _eputchar(BUF_FLUSH);
        r = get_input(info);
        if (r != -1)
        {
            set_info(info, av);
            builtin_rec = find_builtin(info);
            if (builtin_rec == -1)
                find_cmd(info);
        }
        else if (interactive(info))
            _putchar('\n');
        free_info(info, 0);
    }
    write_history(info);
    free_info(info, 1);
    if (!interactive(info) && info->status)
        exit(info->status);
    if (builtin_rec == -2)
    {
        if (info->err_num == -1)
            exit(info->status);
        exit(info->err_num);
    }
    return (builtin_ret);
}