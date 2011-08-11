/**
 *  \file   mainpage.h
 *  \brief  Starting point for documentation (no code)
 *  \author Joshua Bialkowski (jbialk@mit.edu)
 *  \date   Aug 11, 2011

\mainpage   svg2x Documentation

\b svg2x is composed of two binaries \b svg2pdf and \b svg2eps.

\section svg2pdf

\b svg2pdf is a command line utility to convert documents in
Scalable Vector Graphics (svg) format into Adobe Portable Document Format (pdf)
documents, preserving vector graphics

usage:
\verbatim
svg2pdf input_file.svg output_file.pdf
\endverbatim

\section svg2eps

\b svg2eps is a command line utility to convert documents in
Scalable Vector Graphics (svg) format into Adobe Ecapsulated Post-Script (eps)
documents, preserving vector graphics

usage:
\verbatim
svg2eps input_file.svg output_file.eps
\endverbatim


The programs are very simple. They use librsvg to read svg documents, and
cairo to write the pdf and eps documents. These codes are trivial extensions of
those written by Carl Worth.

 */








