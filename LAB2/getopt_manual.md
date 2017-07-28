Last login: Fri Jul 28 09:39:27 on ttys003
macs-iMac:~ tear$ man 3 getopt


     The getopt() function returns the next known option character in
     optstring.  If getopt() encounters a character not found in optstring or
     if it detects a missing option argument, it returns `?' (question mark).
     If optstring has a leading `:' then a missing option argument causes `:'
     to be returned instead of `?'.  In either case, the variable optopt is
     set to the character that caused the error.  The getopt() function
     returns -1 when the argument list is exhausted.

EXAMPLES
     #include <unistd.h>
     int bflag, ch, fd;

     bflag = 0;
     while ((ch = getopt(argc, argv, "bf:")) != -1) {
             switch (ch) {
             case 'b':
                     bflag = 1;
                     break;
             case 'f':
                     if ((fd = open(optarg, O_RDONLY, 0)) < 0) {
                             (void)fprintf(stderr,
                                 "myname: %s: %s\n", optarg, strerror(errno));
                             exit(1);
                     }
                     break;
             case '?':
             default:
                     usage();
             }
     }
     argc -= optind;
     argv += optind;

DIAGNOSTICS
     If the getopt() function encounters a character not found in the string
     optstring or detects a missing option argument it writes an error message
     to the stderr and returns `?'.  Setting opterr to a zero will disable
     these error messages.  If optstring has a leading `:' then a missing
     option argument causes a `:' to be returned in addition to suppressing
     any error messages.

     Option arguments are allowed to begin with ``-''; this is reasonable but
     reduces the amount of error checking possible.

SEE ALSO
     getopt(1), getopt_long(3), getsubopt(3)

STANDARDS
     The optreset variable was added to make it possible to call the getopt()
     function multiple times.  This is an extension to the IEEE Std 1003.2
     (``POSIX.2'') specification.

HISTORY
     The getopt() function appeared in 4.3BSD.

BUGS
     The getopt() function was once specified to return EOF instead of -1.
     This was changed by IEEE Std 1003.2-1992 (``POSIX.2'') to decouple
     getopt() from <stdio.h>.

     A single dash ``-'' may be specified as a character in optstring, however
     it should never have an argument associated with it.  This allows
     getopt() to be used with programs that expect ``-'' as an option flag.
     This practice is wrong, and should not be used in any current develop-
     ment.  It is provided for backward compatibility only.  Care should be
     taken not to use `-' as the first character in optstring to avoid a
     semantic conflict with GNU getopt(), which assigns different meaning to
     an optstring that begins with a `-'.  By default, a single dash causes
     getopt() to return -1.

     It is also possible to handle digits as option letters.  This allows
     getopt() to be used with programs that expect a number (``-3'') as an
     option.  This practice is wrong, and should not be used in any current
     development.  It is provided for backward compatibility only.  The fol-
     lowing code fragment works in most cases.

           int ch;
           long length;
           char *p, *ep;

           while ((ch = getopt(argc, argv, "0123456789")) != -1)
                   switch (ch) {
                   case '0': case '1': case '2': case '3': case '4':
                   case '5': case '6': case '7': case '8': case '9':
                           p = argv[optind - 1];
                           if (p[0] == '-' && p[1] == ch && !p[2]) {
                                   length = ch - '0';
                                   ep = "";
                           } else if (argv[optind] && argv[optind][1] == ch) {
                                   length = strtol((p = argv[optind] + 1),
                                       &ep, 10);
                                   optind++;
                                   optreset = 1;
                           } else
                                   usage();
                           if (*ep != '\0')
                                   errx(EX_USAGE, "illegal number -- %s", p);
                           break;
                   }

BSD                             April 27, 1995                             BSD
(END)
