
DOC=doc

build:
	latex -shell-escape $(DOC)
	bibtex $(DOC)
	latex -shell-escape $(DOC)
	pdflatex -shell-escape $(DOC)

render: build
	open -a Preview $(DOC).pdf
