#!/usr/bin/python
# Most of the credit for this file goes to the Stanford University ACM team

import os
import subprocess
import sys

title = "INSA Lyon ACM-ICPC Team Notebook"

def get_sections(path):
    sections = []
    section_name = None
    with open(os.path.join(path,'contents.txt'), 'r') as f:
        for line in f:
            if '#' in line: line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0: continue
            if line[0] == '[':
                section_name = line[1:-1]
                subsections = []
                if section_name is not None:
                    sections.append((section_name, subsections))
            else:
                tmp = line.split('\t', 1)
                if len(tmp) == 1:
                    raise ValueError('Subsection parse error: %s' % line)
                filename = path + '/' + tmp[0] # Should use os.path.join but it breaks LaTeX with backslashes
                subsection_name = tmp[1]
                if subsection_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp', 'h']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:
        return 'txt'

# TODO: check if this is everything we need
def texify(s):
    #s = s.replace('\'', '\\\'')
    #s = s.replace('\"', '\\\"')
    return s

def get_tex(sections):
    tex = ''
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % texify(section_name)
        for (filename, subsection_name) in subsections:
            tex += '\\subsection{%s}\n' % texify(subsection_name)
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
            tex += '\\hrulefill\n'
        tex += '\n'
    return tex

if __name__ == "__main__":
    if len(sys.argv) == 0:
        print('Usage : %s [python|cpp]' % sys.argv[0])
    basepath = sys.argv[1]
    assert basepath in ('python','cpp')
    sections = get_sections(basepath)
    tex = get_tex(sections)
    with open('contents_'+basepath+'.tex', 'wb') as f:
        f.write(tex)
    latexmk_options = ["latexmk", "-pdf", "notebook_"+basepath+".tex"]
    subprocess.call(latexmk_options)
