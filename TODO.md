Wstępna propozycja szkicu dokumentacji funkcjonalnej
-

Fragmenty oznaczone kursywą to funkcjonalności których nie jestem pewien (czy damy radę, czy warto etc.)

- [x] @mentions, #refs, [links](), **formatting**, and <del>tags</del> supported
- [x] list syntax required (any unordered or ordered list supported)
- [x] this is a complete item
- [ ] this is an incomplete item

<b>Budowa programu</b>

- [x] Aplikacja będzie się składać z dwóch modułów, nazwanych roboczo Klient i Serwer.
- 
- das
- 
- dasdasdas

dsdsad

x Klient

	program, którego zadaniem jest komunikacja z użytkownikiem. 
	Na początku wyświetla okno z opcjami (zwane dalej ekranem startowym), 
	w którym użytkownik może dobrać pewne parametry „rozgrywki”. 
	Następnie uruchamia Serwer i przesyła mu zebrane dane, wtedy rozpoczyna się właściwa symulacja. 
	Podczas symulacji Klient odbiera od Serwera informacje o obecnych wynikach symulacji 
	i na bieżąco wyświetla graficzną planszę oraz wysyła Serwerowi informacje 
	o kliknięciach użytkownika (w czasie symulacji użytkownik 
	może przyspieszać, zwalniać lub wstrzymywać symulację). 
	Do wyświetlania planszy klient używa biblioteki OpenGL. 

x Serwer
	program, którego zadaniem jest obliczać kolejne kroki symulacji z zadaną częstotliwością 
	i wysyłać wyniki obliczeń do klienta. Serwer może także przyspieszać, zwalniać lub wstrzymywać symulację 
	na żądanie użytkownika (przekazywane za pośrednictwem klienta).

- [] Klient i serwer komunikują się za pomocą współdzielonej pamięci, która jest zrealizowana przy pomocy biblioteki Boost::Interprocess. 


„Świat gry”
Symulacja rozgrywa się na prostokątnej planszy, której wymiary ustala użytkownik na ekranie startowym. Początkowo obiekty zostają umieszczone w sposób losowy, ale z ograniczeniami opisanymi niżej. Rodzaje obiektów:
osobnik (roślinożerca lub drapieżnik), posiada zestaw indywidualnych cech; stanowi punkt (nie ma wymiarów), może się poruszać
drzewo – źródło pożywienia dla roślinożerców; stanowi punkt (nie ma wymiarów) 
wodopój – źródło wody dla osobników; stanowi punkt (nie ma wymiarów) 
jaskinia – miejsce, w którym osobniki mogą spać; stanowi punkt (nie ma wymiarów) 
skały – obszar na planszy, po którym osobniki nie mogą chodzić, stanowi koło o promieniu 5 jednostek; takie koła mogą się częściowo nakładać, tworząc większe struktury
Cechy (parametry) osobników
Każdy osobnik posiada zestaw indywidualnych cech, ustalanych w momencie narodzin (liczby całkowite):
Zasięg widzenia (ozn. R), R ∈ [5, 100]
Szybkość biegu (V), V ∈ [5, 100]
Odporność na głód (F), F ∈ [5, 100]
Odporność na pragnienie (W), W ∈ [5, 100]
Wytrzymałość [odporność na zmęczenie] (S), S ∈ [5, 100]
Wydajność reprodukcyjna (P), P ∈ [5, 100]
Maksymalny czas życia (L), L ∈ [5, 100]
Płeć (X), X ∈ {„F”, „M”}
Indywidualne cechy osobnika (z wyjątkiem płci) mają tę własność, że „więcej = lepiej”. Spełniają one warunek: R+V+F+W+S+P = 200
A także parametry chwilowe (liczby rzeczywiste, zmieniające się w sposób pseudo-ciągły):
Poziom najedzenia (ozn. f), f ∈ [0, F], maleje w stałym tempie
Jeśli poziom najedzenia spadnie poniżej połowy (f ∈ [0, ½F]), to osobnik znajduje się w stanie „głodny”
Jeśli głodny osobnik dotrze do drzewa (roślinożerca) lub złapie roślinożercę (drapieżnik) jego poziom napojenia natychmiast rośnie do poziomu F. Roślinożerca zjedzony przez drapieżnika znika z gry.
Jeśli poziom najedzenia spadnie do zera, osobnik umiera z głodu
Poziom napojenia (w) w ∈  [0, W], maleje w stałym tempie
Jeśli poziom napojenia spadnie poniżej połowy (w ∈ [0, ½w]), to osobnik znajduje się w stanie „spragniony”.
Jeśli spragniony osobnik dotrze do wodopoju, jego poziom napojenia natychmiast rośnie do poziomu W
Jeśli poziom napojenia spadnie do zera, osobnik umiera z pragnienia
Poziom energii (wypoczęcia) (s) s ∈ [0, S], maleje w zmiennym tempie
Jeśli poziom energii spadnie poniżej połowy (s ∈ [0, ½S]), to osobnik znajduje się w stanie „zmęczony”. 
Jeśli głodny osobnik dotrze do kryjówki, jego poziom napojenia energii rośnie do poziomu S, ale jednocześnie zapada on w sen trwający stały czas TS. W czasie snu osobnik nie porusza się, jest niewidoczny dla innych osobników, ale może zostać zjedzony przez drapieżnika, który akurat wejdzie do tej samej kryjówki.
Jeśli poziom energii spadnie do zera, osobnik umiera z wycieńczenia
Poziom energii maleje dwa razy szybciej podczas biegu.
Czas do reprodukcji (p), p ∈ [0, 1], maleje w stałym tempie (zależnym od wartości P)
Jeśli p = 0, to osobnik może się rozmnażać; po akcie „kopulacji” wartość p jest ustawiana na 1. Wartość ta maleje w tempie P/1000 na sekundę (czyli osobnik o najwyższej możliwej zdolności reprodukcyjnej P=100 będzie „pauzować” 10 sekund, a o najniższej możliwej P=5, będzie „pauzować” 200 sekund).
Wiek (l), l ∈ [0, L],  rośnie w stałym tempie
Przy narodzinach jest ustawiane l = 0, po osiągnięciu l = L osobnik umiera ze starości
Zachowanie osobników
Każdy osobnik porusza się po planszy w sposób losowy, dopóki w jego polu widzenia (okrąg o promieniu R) nie znajdzie się jakiś interesujący go obiekt:
Jeśli w polu widzenia osobnika znajduje się jaskinia i osobnik jest zmęczony, to idzie w stronę wodopoju – priorytet 1.
Jeśli w polu widzenia osobnika znajduje się drzewo, osobnik jest głodny i jest roślinożercą, to osobnik idzie w stronę drzewa – priorytet 2.
Jeśli w polu widzenia osobnika znajduje się wodopój i osobnik jest spragniony, to osobnik idzie w stronę wodopoju – priorytet 3.
Jeśli w polu widzenia osobnika znajduje się drugi osobnik tego samego gatunku i przeciwnej płci oraz oba te osobniki mają p=0 (są gotowe do reprodukcji) oraz żaden z nich nie jest głodny, spragniony, ani zmęczony, to osobniki idą w swoim kierunku – priorytet 4.
Jeśli w polu widzenia osobnika znajduje się roślinożerca, osobnik jest głodny i jest drapieżnikiem, to osobnik biegnie w stronę roślinożercy (poluje) – priorytet 5.
Jeśli w polu widzenia osobnika znajduje się drapieżnik i osobnik jest roślinożercą, to osobnik biegnie w stronę przeciwną (ucieka), niezależnie od tego, czy drapieżnik jest głodny – priorytet 5.
Jakieś zachowania społeczne – osobniki mogą trzymać się innych osobników swojego gatunku, wspólnie polować etc. – tylko nie mam pojęcia, jak to realizować. 
Jeśli w zasięgu wzroku osobnika znajduje się kilka interesujących obiektów, to wybiera akcję o najwyższym priorytecie (najpierw polowanie / ucieczka itd.).
Rozmnażanie
Jeśli dwa osobniki tego samego gatunku i różnych płci spotkają się, następuje akt prokreacji – pojawia się nowy osobnik, którego cechy (R, V, F, W, S, P, L) wynikają z odpowiednich cech rodziców:
RDZIECKA = random(ROJCA, RMATKI) + random(-10, 10) (analogicznie dla pozostałych cech)
gdzie random(a,b) jest funkcją zwracającą losową wartość z zakresu [min(a,b);max(a,b)]. Cechy są skalowane w taki sposób, aby spełniały warunki: R+V+F+W+S+P+L=200; R, V, F, W, S, P, L ∈ [5, 100].
Możliwości modyfikacji scenariusza
Na ekranie startowym użytkownik może ustalić pewne parametry symulacji, takie jak: wielkość planszy, gęstość rozmieszczenia drzew, wodopojów, skał, ilość drapieżników i roślinożerców etc., a także wpłynąć na określone cechy całej populacji (np. dodać wszystkim roślinożercom +30 do szybkości). Do programu będzie też dołączonych kilka (wybranych przez twórców gry) ciekawych scenariuszy. 
Wizualizacja
Osobniki i inne obiekty będą reprezentowane przez proste figury geometryczne, po najechaniu myszką na obiekt wyświetli się więcej informacji o nim.

This post examines the features of [R Markdown](http://www.rstudio.org/docs/authoring/using_markdown) 
using [knitr](http://yihui.name/knitr/) in Rstudio 0.96.
This combination of tools provides an exciting improvement in usability for 
[reproducible analysis](http://stats.stackexchange.com/a/15006/183).
Specifically, this post 
(1) discusses getting started with R Markdown and `knitr` in  Rstudio 0.96;
(2) provides a basic example of producing console output and plots using R Markdown;
(3) highlights several code chunk options such as caching and controlling how input and output is displayed;
(4) demonstrates use of standard Markdown notation as well as the extended features of formulas and tables; and 
(5) discusses the implications of R Markdown.
This post was produced with R Markdown. The source code is available here as a gist. 
The post may be most useful if the source code and displayed post are viewed side by side. 
In some instances, I include a copy of the R Markdown in the displayed HTML, but most of the time I assume you are reading the source and post side by side.

<!-- more -->


## Getting started
To work with R Markdown, if necessary:

* Install [R](http://www.r-project.org/)
* Install the lastest version of [RStudio](http://rstudio.org/download/) (at time of posting, this is 0.96)
* Install the latest version of the `knitr` package: `install.packages("knitr")`

To run the basic working example that produced this blog post:

* Open R Studio, and go to File - New - R Markdown
* If necessary install `ggplot2` and `lattice` packages: `install.packages("ggplot2"); install.packages("lattice") `
* Paste in the contents of this gist (which contains the R Markdown file used to produce this post) and save the file with an `.rmd` extension
* Click Knit HTML




## Prepare for analyses
```{r setup}
set.seed(1234)
library(ggplot2)
library(lattice)
```


## Basic console output
To insert an R code chunk, you can type it manually or just press `Chunks - Insert chunks` or use the shortcut key. This will produce the following code chunk:

    ```{r}
    
    ```

Pressing tab when inside the braces will bring up code chunk options.

The following R code chunk labelled `basicconsole` is as follows:

    ```{r basicconsole}
    x <- 1:10
    y <- round(rnorm(10, x, 1), 2)
    df <- data.frame(x, y)
    df
    ```
The code chunk input and output is then displayed as follows:

```{r basicconsole}
x <- 1:10
y <- round(rnorm(10, x, 1), 2)
df <- data.frame(x, y)
df
```

## Plots
Images generated by `knitr` are saved in a figures folder. However, they also appear to be represented in the HTML output using a [data URI scheme]( http://en.wikipedia.org/wiki/Data_URI_scheme). This means that you can paste the HTML into a blog post or discussion forum and you don't have to worry about finding a place to store the images; they're embedded in the HTML.

### Simple plot
Here is a basic plot using base graphics:

    ```{r simpleplot}
    plot(x)
    ```

```{r simpleplot}
plot(x)
```

Note that unlike traditional Sweave, there is no need to write `fig=TRUE`.


### Multiple plots
Also, unlike traditional Sweave, you can include multiple plots in one code chunk:

    ```{r multipleplots}
    boxplot(1:10~rep(1:2,5))
    plot(x, y)
    ```

```{r multipleplots}
boxplot(1:10~rep(1:2,5))
plot(x, y)
```

### `ggplot2` plot
Ggplot2 plots work well:

```{r ggplot2ex}
qplot(x, y, data=df)
```

### `lattice` plot
As do lattice plots:

```{r latticeex}
xyplot(y~x)
```

Note that unlike traditional Sweave, there is no need to print lattice plots directly.

## R Code chunk features
### Create Markdown code from R
The following code hides the command input (i.e., `echo=FALSE`), and outputs the content directly as code (i.e., `results=asis`, which is similar to `results=tex` in Sweave).


    ```{r dotpointprint, results='asis', echo=FALSE}
    cat("Here are some dot points\n\n")
    cat(paste("* The value of y[", 1:3, "] is ", y[1:3], sep="", collapse="\n"))
    ```

```{r dotpointprint, results='asis', echo=FALSE}
cat("Here are some dot points\n\n")
cat(paste("* The value of y[", 1:3, "] is ", y[1:3], sep="", collapse="\n"))
```

### Create Markdown table code from R
    ```{r createtable, results='asis', echo=FALSE}
    cat("x | y", "--- | ---", sep="\n")
    cat(apply(df, 1, function(X) paste(X, collapse=" | ")), sep = "\n")
    ```

```{r createtable, results='asis', echo=FALSE}
cat("x | y", "--- | ---", sep="\n")
cat(apply(df, 1, function(X) paste(X, collapse=" | ")), sep = "\n")
```

### Control output display
The folllowing code supresses display of R input commands (i.e., `echo=FALSE`)
and removes any preceding text from console output (`comment=""`; the default is `comment="##"`).

    ```{r echo=FALSE, comment="", echo=FALSE}
    head(df)
    ```

```{r echo=FALSE, comment="", echo=FALSE}
head(df)
```



### Control figure size
The following is an example of a smaller figure using `fig.width` and `fig.height` options.

    ```{r smallplot, fig.width=3, fig.height=3}
    plot(x)
    ```

```{r smallplot, fig.width=3, fig.height=3}
plot(x)
```

### Cache analysis
Caching analyses is straightforward.
Here's example code. 
On the first run on my computer, this took about 10 seconds.
On subsequent runs, this code was not run. 

If you want to rerun cached code chunks, just [delete the contents of the `cache` folder](http://stackoverflow.com/a/10629121/180892)

    ```{r longanalysis, cache=TRUE}
    for (i in 1:5000) {
        lm((i+1)~i)
    }
    ```

## Basic markdown functionality
For those not familiar with standard [Markdown](http://daringfireball.net/projects/markdown/), the following may be useful.
See the source code for how to produce such points. However, RStudio does include a Markdown quick reference button that adequatly covers this material.

### Dot Points
Simple dot points:

* Point 1
* Point 2
* Point 3

and numeric dot points:

1. Number 1
2. Number 2
3. Number 3

and nested dot points:

* A
    * A.1
    * A.2
* B
    * B.1
    * B.2


### Equations
Equations are included by using LaTeX notation and including them either between single dollar signs (inline equations) or double dollar signs (displayed equations).
If you hang around the Q&A site [CrossValidated](http://stats.stackexchange.com) you'll be familiar with this idea.

There are inline equations such as $y_i = \alpha + \beta x_i + e_i$.

And displayed formulas:

$$\frac{1}{1+\exp(-x)}$$


knitr provides self-contained HTML code that calls a Mathjax script to display formulas.
However, in order to include the script in my blog posts I [took the script](https://gist.github.com/2716053) and incorporated it into my blogger template.
If you are viewing this post through syndication or an RSS reader, this may not work.
You may need to view this post on my website. 

### Tables
Tables can be included using the following notation

A  | B | C
--- | --- | ---
1  | Male | Blue
2  | Female | Pink

### Hyperlinks

* If you like this post, you may wish to subscribe to [my RSS feed](http://feeds.feedburner.com/jeromyanglim).

### Images
Here's an example image:

![image from redmond barry building unimelb](http://i.imgur.com/RVNmr.jpg)


### Code
Here is Markdown R code chunk displayed as code:

    ```{r}
    x <- 1:10
    x
    ```
    


And then there's inline code such as `x <- 1:10`.

### Quote
Let's quote some stuff:

> To be, or not to be, that is the question:
> Whether 'tis nobler in the mind to suffer
> The slings and arrows of outrageous fortune,


## Conclusion

* R Markdown is awesome. 
    * The ratio of markup to content is excellent. 
    * For exploratory analyses, blog posts, and the like R Markdown will be a powerful productivity booster. 
    * For journal articles, LaTeX will presumably still be required.
* The RStudio team have made the whole process very user friendly.
    * RStudio provides useful shortcut keys for compiling to HTML, and running code chunks. These shortcut keys are presented in a clear way.
    * The incorporated extensions to Markdown, particularly formula and table support, are particularly useful.
    * Jump-to-chunk feature facilitates navigation. It helps if your code chunks have informative names.
    * Code completion on R code chunk options is really helpful. See also [chunk options documentation on the knitr website](http://yihui.name/knitr/options).
* Other recent posts on R markdown include those by :
     * [Christopher Gandrud](http://christophergandrud.blogspot.com.au/2012/05/dynamic-content-with-rstudio-markdown.html)
     * [Markcus Gesmann](http://lamages.blogspot.com.au/2012/05/interactive-reports-in-r-with-knitr-and.html)
     * [Rstudio on R Markdown](http://rstudio.org/docs/authoring/using_markdown)
     * [Yihui Xie](http://yihui.name/knitr/): I really want to thank him for developing `knitr`. 
     He has also posted [this example of R Markdown](https://github.com/yihui/knitr/blob/master/inst/examples/knitr-minimal.Rmd).


## Questions
The following are a few questions I encountered along the way that might interest others.
### Annoying `<br/>`'s
**Question:** I asked on the Rstudio discussion site:
[Why does Markdown to HTML insert `<br/>` on new lines?](http://support.rstudio.org/help/discussions/problems/2329-why-does-r-markdown-to-html-insert-br-when-there-is-a-new-line-of-text)

**Answer:** I just do a find and delete on this text for now.

### Temporarily disable caching
**Question:** I asked on StackOverflow about 
[How to set cache=FALSE for a knitr markdown document and override code chunk settings?](http://stackoverflow.com/q/10628665/180892)

**Answer:**  Delete the cache folder. But there are other possible workflows.

### Equivalent of Sexpr
**Question:** I asked on Stack Overvlow about [whether there an R Markdown equivalent to Sexpr in Sweave?](http://stackoverflow.com/q/10629416/180892).

**Answer:** Include the code between brackets of "backick r space" and "backtick". 
E.g., in the source code I have calculated 2 + 2 = `r 2 + 2` .
