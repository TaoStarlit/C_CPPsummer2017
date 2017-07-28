https://www.tutorialspoint.com/unix/unix-io-redirections.htm

Input Redirection
Just as the output of a command can be redirected to a file, so can the input of a command be redirected from a file. As the greater-than character > is used for output redirection, the less-than character < is used to redirect the input of a command.

The commands that normally take their input from the standard input can have their input redirected from a file in this manner. For example, to count the number of lines in the file users generated above, you can execute the command as follows −

$ wc -l users
2 users
$
Upon execution, you will receive the following output. You can count the number of lines in the file by redirecting the standard input of the wc command from the file users −

$ wc -l < users
2
$
Note that there is a difference in the output produced by the two forms of the wc command. In the first case, the name of the file users is listed with the line count; in the second case, it is not.

In the first case, wc knows that it is reading its input from the file users. In the second case, it only knows that it is reading its input from standard input so it does not display file name.







macs-iMac:doc tear$ man 1 wc

     by a <newline> character.  Characters beyond the final <newline> charac-
     ter will not be included in the line count.

     A word is defined as a string of characters delimited by white space
     characters.  White space characters are the set of characters for which
     the iswspace(3) function returns true.  If more than one input file is
     specified, a line of cumulative counts for all the files is displayed on
     a separate line after the output for the last file.

     The following options are available:

     -c      The number of bytes in each input file is written to the standard
             output.  This will cancel out any prior usage of the -m option.

     -l      The number of lines in each input file is written to the standard
             output.

     -m      The number of characters in each input file is written to the
             standard output.  If the current locale does not support multi-
             byte characters, this is equivalent to the -c option.  This will
             cancel out any prior usage of the -c option.

     -w      The number of words in each input file is written to the standard
             output.

     When an option is specified, wc only reports the information requested by
     that option.  The order of output always takes the form of line, word,
     byte, and file name.  The default action is equivalent to specifying the
     -c, -l and -w options.

     If no files are specified, the standard input is used and no file name is
     displayed.  The prompt will accept input until receiving EOF, or [^D] in
     most environments.

ENVIRONMENT
     The LANG, LC_ALL and LC_CTYPE environment variables affect the execution
     of wc as described in environ(7).

EXIT STATUS
     The wc utility exits 0 on success, and >0 if an error occurs.

EXAMPLES
     Count the number of characters, words and lines in each of the files
     report1 and report2 as well as the totals for both:

           wc -mlw report1 report2

COMPATIBILITY
     Historically, the wc utility was documented to define a word as a ``maxi-
     mal string of characters delimited by <space>, <tab> or <newline> charac-
     ters''.  The implementation, however, did not handle non-printing charac-
     ters correctly so that ``  ^D^E  '' counted as 6 spaces, while
     ``foo^D^Ebar'' counted as 8 characters.  4BSD systems after 4.3BSD modi-
     fied the implementation to be consistent with the documentation.  This
     implementation defines a ``word'' in terms of the iswspace(3) function,
     as required by IEEE Std 1003.2 (``POSIX.2'').

SEE ALSO
     iswspace(3)

STANDARDS
     The wc utility conforms to IEEE Std 1003.1-2001 (``POSIX.1'').

HISTORY
     A wc command appeared in Version 1 AT&T UNIX.

BSD                            February 23, 2005                           BSD
(END)
