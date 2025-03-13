# 42-minishell
Duo team with Tansel (tbayrakt)

The Concept & How It Is Supposed To Work:

The conventional shell seems to be smart enough to execute the commands properly even though the ordering of target file/folder and command flags are unconventional.
Therefore, our minishell is aimed to replicate the same intelligence. Although unable to cover the same number of redirect symbols, it should be enough to cover all criteria required by the subject.

The way we aimed to approach are as follows:

As the input will always be normalized into a single line of string (*str), the program should be able to recognize the redirect symbols when encountered. As such;
- If str[i] == (symbol 'x'), denote at set t_struct so it can be referenced in later steps, else i++.
- If str[i] == (symbol 'y'1) && str[i + 1] == (symbol 'y'2), as certain symbols requires multiple characters (such as <<, >>, &&, ||), it should also denotes.
- If str[i] == (symbol 'q'), which represents quotations (notably ' and "), it should denote so that the split will handle differently, results wise.
- As redirect symbols may link to piping and fd communication, the program should also be able to handle multiple symbols and commands within one line.
- Ultimately, the program should be able to return exit status (errno) identical to the conventional shell with no internal memory leaks nor crashes.
