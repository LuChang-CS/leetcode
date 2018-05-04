% title page
\makeatletter
\def\maketitle{
    \fontsize{18}{20}\selectfont\par\noindent\textcolor{darkgray}{\textsc{\@author}}%
    \vspace{11.5pc}%
    \fontsize{34}{40}\selectfont\par\noindent{\textbf{\@title}}%
    \vspace{0.2in}
    \fontsize{14}{14}\selectfont\par\noindent\textbf{\textit{\@date}}
    \vfill
    \thispagestyle{empty}}
\makeatother
%

% remove blank page
\let\cleardoublepage\clearpage
%

% chapter title format
\newfontfamily\headingfont[]{Arial}
\titleformat{\chapter}[display]
{\normalfont\Huge\bfseries\headingfont}
{\chaptertitlename\ \thechapter}{5pt}{\phantomsection}
%

% paragraph format
\setlength{\parindent}{2em}
\setlength{\parskip}{0.6em}
\renewcommand{\baselinestretch}{1.2}
%

% content format
\setlength{\cftsecindent}{0.2cm}

% font for kannada
\newfontfamily\kannadafont[Script=Kannada]{Noto Sans Kannada}.
%

% code format
\setmonofont{Consolas}
\definecolor{codebackground}{RGB}{244,244,244}
\newfontfamily\codefont[Scale=0.8]{Consolas}
\def\ininecode{code}
\newcommand{\inlinecode}[1]{
	\colorbox{codebackground}{\codefont#1}}
\lstnewenvironment{multilinecode}{
    \lstset{
        backgroundcolor=\color{codebackground},
        basicstyle=\codefont,
        keywordstyle=\bfseries,
        showstringspaces=false,
        xleftmargin=1em,
        framexleftmargin=1em,
        breaklines=true,
        breakindent=0em,
        mathescape=true,
        postbreak=\mbox{{$\hookrightarrow$}\space},
        morekeywords={Input, Output, Explanation}}}{}
%

% define Example
\newtheoremstyle{definition}
{}{}
{}{}
{\bfseries}{}
{\newline}{}
\theoremstyle{definition}
\newtheorem{example}{Example}
\counterwithin*{example}{section}
%

% section format
\titleformat{\section}
{\normalfont\Large\bfseries\headingfont}
{\thesection}{0in}{\phantomsection}
\newcommand{\nocontentsline}[3]{}
\newcommand{\tocless}[2]{\bgroup\let\addcontentsline=\nocontentsline#1{#2}\egroup}
\renewcommand\thesection{}
%
