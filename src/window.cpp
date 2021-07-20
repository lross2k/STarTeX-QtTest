#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    // Window
    setWindowTitle(tr("STartTeX"));

    // Initializing private objects
    CustomChecks = new EasyCustomChecks();
    Templates = new TemplateView();
    CreateButton = new QPushButton("Generate document");

    // Tabs
    TabWidget = new QTabWidget;
    TabWidget->addTab(CustomChecks, tr("Quick Custom"));
    TabWidget->addTab(Templates, tr("Templates"));

    // Layout
    QVBoxLayout *MainLayout = new QVBoxLayout();
    MainLayout->addWidget(TabWidget);
    MainLayout->addWidget(CreateButton);
    setLayout(MainLayout);

    // Connect signals
    connect(CreateButton, SIGNAL(clicked(bool)), this, SLOT(WriteDocument()));
}

void Window::WriteDocument()
{
    // cpp boilerplate
    using namespace std;

    // defining constant information text
    const string headerText =   "% * * * * * * * * * * * * * *\n"
                                "% Generated using STartTeX\n"
                                "% v0.0.3d\n"
                                "% * * * * * * * * * * * * * *\n\n";

    // declaring variables;
    string includeStr, documentStr, commandsStr;
    QFile   includeFile("./generated/include.tex"),
            documentFile("./generated/main.tex"),
            commandsFile("./generated/commands.tex");

    // setting up starting values
    includeStr = headerText;
    documentStr = headerText;
    commandsStr = headerText;

    documentStr +=  "\\documentclass{" + CustomChecks->GetDocuClass() + "}\n\n"
                    "\\input{include}\n"
                    "\\input{commands}\n\n"
                    "\\begin{document}\n\n";

    // filler body for the base document
    documentStr += "Showing some \\textit{basic text} in the \\textbf{document file} \\bigskip\n\n";

    // package configuration could be branchless but meh
    if (CustomChecks->CheckedGeometry()) {
        includeStr +=  "\\usepackage{geometry}\n"
                        "\\geometry{letterpaper} % geometry config\n\n";
    }
    if (CustomChecks->CheckedHyperref()) {
        includeStr +=  "\\usepackage{hyperref}\n"
                        "\\hypersetup{\n"
                            "colorlinks=true,\n"
                            "linkcolor=blue,\n"
                            "filecolor=magenta,\n"
                            "urlcolor=blue,\n"
                            "citecolor=blue,\n"
                        "}\n\n";
        documentStr += "Hyperref allows for easier to spot hyperlinks\n"
                        "Check the STartTeX \\href{https://youtu.be/dQw4w9WgXcQ}{repository} to contribute. \\bigskip\n\n";
    }
    if (CustomChecks->CheckedEnumitem()) {
        includeStr += "\\usepackage{enumitem}";
        documentStr += "Showing alphabetic enumeration.\n"
                        "\\begin{enumerate}[label=\\alph*)]\n"
                            "\t\\item Is before b\n"
                            "\t\\item Is at b\n"
                            "\t\\item Is after b\n"
                        "\\end{enumerate} \\bigskip\n\n";
    }
    if (CustomChecks->CheckedInputenc()) {
        includeStr += "\\usepackage[utf8x]{inputenc}\n\n";
    }
    if (CustomChecks->CheckedMath()) {
        includeStr += "\\usepackage{amsmath}\n\n";
        documentStr += "Simple equation example.\n\n"
                        "\\begin{equation}\n"
                            "\t\\tilde k_{\\lambda_j} = P_{\\tilde{\\mathcal{M}}}\n"
                        "\\end{equation} \\bigskip\n\n";
    }
    if (CustomChecks->CheckedTCBox()) {
        includeStr += "\\usepackage{tcolorbox}\n\n";
        documentStr += "Showing a simple box.\n"
                        "\\begin{tcolorbox}\n"
                            "\tThis is a tcolorbox example\n"
                        "\\end{tcolorbox} \\bigskip\n\n";
    }
    if (CustomChecks->CheckedGraphicx()) {
        includeStr += "\\usepackage{graphicx}\n\n";
        documentStr += "Including pictures with graphicx.\n"
                        "\\begin{figure}[!htbp]\n"
                            "\t\\centering\n"
                            "\t\\includegraphics[width=0.4\\textwidth]{example.jpg}\n"
                            "\t\\caption{Caption of the example}\n"
                            "\t\\label{fig:example_fig}\n"
                        "\\end{figure} \\bigskip\n\n";
    }
    if (CustomChecks->CheckedFloat()) {
        includeStr += "\\usepackage{float}\n\n";
    }
    if (CustomChecks->CheckedCircuit()) {
        includeStr += "\\usepackage[siunitx,RPvoltages,american]{circuitikz}\n\n";
        documentStr += "Rendering a circuit with circuitikz.\n"
                        "\\begin{center}"
                            "\t\\begin{circuitikz} \\draw\n"
                                "\t\t(0,0) to[battery] (0,4)\n"
                                "\t\tto[ammeter] (4,4) -- (4,0)\n"
                                "\t\tto[lamp] (0,0);\n"
                            "\t\\end{circuitikz}\n"
                        "\\end{center} \\bigskip\n\n";
    }
    if (CustomChecks->CheckedListings()) {
        includeStr +=  "\\usepackage{listings}\n\n"
                        "\\lstdefinestyle{mystyle}{\nshowstringspaces=false\n}\n"
                        "\\lstset{style=mystyle}\n\n";
        documentStr += "Embedding code from the \\textbf{example.f90 file}.\n"
                        "\\lstinputlisting[language=Fortran]{example.f90} \\bigskip\n\n";
    }

    // final lines for the files
    documentStr += "\\end{document}\n\n% STartTeX generation ended\n";
    includeStr += "% STartTeX generation ended\n";

    // writing to the files
    if ( includeFile.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &includeFile );
        stream << QString::fromUtf8(includeStr.c_str());
    }
    if ( documentFile.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &documentFile );
        stream << QString::fromUtf8(documentStr.c_str());
    }
    if ( commandsFile.open(QIODevice::WriteOnly) )
    {
        QTextStream stream( &commandsFile );
        stream << QString::fromUtf8(commandsStr.c_str());
    }
}
