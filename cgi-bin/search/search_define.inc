############################################################
#
# Define Variables for the search_engine.inc script
#
############################################################
$root_web_path = "/home/mikeshecket/www/lawschool";
# root_web_path is the path to the directory tree you
# wish to search
#
# server_url is the actual url for this site.  Files that
# are positive matches get prefixed with the url information
# in a hypertext reference.
#Replace domain with your domain name minus the .com

$server_url = "http://lawschool.mikeshecket.com";

#
# unwanted files is a list of pattern matched filenames
# you do not wish to search for keywords in.  Note that
# the pattern matches against the full path and filename
# so that you can exclude certain directories.
# 
@unwanted_files = ("wusage(.*)html",
                   "cgi-bin(.*)html");

# The following are routines that print the HTML code related to
# various parts of the program.  You can edit the cosmetics of the
# program by altering the code below.  This means you can alter
# the cosmetics without directly altering the code in the
# actual search_engine.pl program.
#

############################################################
#
# subroutine: PrintHeaderHTML
#   Usage:
#     &PrintHeaderHTML;
#
#   Parameters:
#     None
#
#   Output:
#     Prints the HTML code for the header of the keyword
#     return results
# 
############################################################

sub PrintHeaderHTML
{

    print <<__HEADERHTML__;
<HTML><BODY BGCOLOR="#ffffff"><HEAD><TITLE>$search_results_title</TITLE></HEAD>
<BODY><CENTER>
<img width=100% src="http://lawschool.mikeshecket.com/searchheader.jpg">
</CENTER>
<CENTER><H2>Let's see if we can find some <I>$keywords</I> for you...</H2></CENTER><UL>
__HEADERHTML__
} # End of PrintHeaderHTML

############################################################
#
# subroutine: PrintFooterHTML
#   Usage:
#     &PrintFooterHTML;
#
#   Parameters:
#     None
#
#   Output:
#     Prints the HTML code for the footer of the keyword
#     return results
# 
############################################################

sub PrintFooterHTML
{
    print <<__FOOTERHTML__;
 </BODY> </HTML>

__FOOTERHTML__

} # End of PrintFooterHTML

############################################################
#
# subroutine: PrintNoHitsBodyHTML
#   Usage:
#     &PrintNoHitsBodyHTML;
#
#   Parameters:
#     None
#
#   Output:
#     Prints the HTML code for the body of the keyword
#     search if no results were found
# 
############################################################

sub PrintNoHitsBodyHTML
{
    print <<__NOHITS__;

<P>
<CENTER>
<H2>Sorry, I couldn't find anything for you.</H2>
</CENTER>
<P>
__NOHITS__

} # End of PrintNoHitsBodyHTML

############################################################
#
# subroutine: PrintBodyHTML
#   Usage:
#     &PrintBodyHTML;
#
#   Parameters:
#     None
#
#   Output:
#     Prints the HTML code for the body of the keyword
#     search result set
# 
############################################################


sub PrintBodyHTML
{
    local($filename, $title) = @_;

    print <<__BODYHTML__;
<LI>
<B>
<A HREF="$server_url/$filename">
$title</A>
</B>
 (/$filename)<BR>
__BODYHTML__

} # End of PrintBodyHTML

############################################################
#
# subroutine: PrintNoKeywordHTML
#   Usage:
#     &PrintNoKeywordHTML;
#
#   Parameters:
#     None
#
#   Output:
#     Prints the HTML code for a form allowing the user
#     to enter a keyword since no keyword was alreay entered
# 
############################################################

sub PrintNoKeywordHTML
{
    print <<__NOKEYHTML__;
<HTML>
<HEAD>
<TITLE>That Krazy Search Engine!</TITLE>
</HEAD> 
<BODY BGCOLOR="#ffffff">
<CENTER>
<img width=100% src="http://lawschool.mikeshecket.com/searchheader.jpg">
</CENTER>
<HR>
<P>
<FORM ACTION="search.pl" METHOD="POST">
<B>Let's do that search thing!  What do you want to look for?</B>
<INPUT TYPE="text" SIZE="30" NAME="keywords" MAXLENGTH="80">
<P>
<INPUT TYPE=checkbox NAME="exact_match"> Exact Match Search
<HR>
<CENTER>
<INPUT TYPE="SUBMIT" VALUE="Submit keywords">
<INPUT TYPE="RESET" VALUE="Clear this form">
</CENTER>
</FORM>
</BODY></HTML>


__NOKEYHTML__

} # End of PrintNoKeywordHTML


