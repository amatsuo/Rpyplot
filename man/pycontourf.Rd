% Generated by roxygen2 (4.1.0): do not edit by hand
% Please edit documentation in R/plot.R
\name{pycontourf}
\alias{pycontourf}
\title{Filled contour using pyplot}
\usage{
pycontourf(x, y, z, args, show = FALSE)
}
\arguments{
\item{x}{numeric vector containing the x coordinates of points}

\item{y}{numeric vector containing the y coordinates of points}

\item{z}{array of z-axis coordinates}

\item{args}{character string of further arguments passed to the **kwargs
argument of matplotlib.pyplot.scatter}

\item{show}{bool indicating whether to open a window with the plot}
}
\description{
Filled contour using pyplot
}
\examples{
x <- 1:ncol(volcano)*.2
y <- 1:nrow(volcano)*.5
pycontourf(x, y, volcano)
if (interactive())
   pyshow()
}

