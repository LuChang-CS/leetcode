% title page
\makeatletter
\def\maketitle{
    \fontsize{18}{20}\selectfont\par\noindent\textcolor{darkgray}{\textsc{\@author}}%
    \vspace{11.5pc}%
    \fontsize{34}{40}\selectfont\par\noindent{\textbf{\@title}}%
    \vspace{0.2in}
    \fontsize{14}{14}\selectfont\par\noindent\textbf{\textit{\@date}}
    \vfill
    \thispagestyle{empty}
}
\makeatother
%

% remove blank page
\let\cleardoublepage\clearpage
%

% chapter title format
\newfontfamily\headingfont[]{Arial}
\titleformat{\chapter}[display]
{\normalfont\sffamily\Huge\bfseries\headingfont}
{\chaptertitlename\ \thechapter}{5pt}{\Huge}
\titleformat{\section}
{\normalfont\sffamily\Large\bfseries\headingfont}
{\thesection}{1em}{}
%

% paragraph format
\setlength{\parindent}{2em}
\setlength{\parskip}{1em}
\renewcommand{\baselinestretch}{1.5}
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
	\colorbox{codebackground}{\codefont#1}
}
%
