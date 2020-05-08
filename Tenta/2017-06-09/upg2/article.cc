

int main()
{
    Report rep {"Anvisning för exjobbsrapporter"};
    rep.authors().push_back("Åberg, Johan");
    {
        Chapter & ch { rep.new_chapter("Om denna handledning") };
        ch.text() = "Denna anvisning går igenom vilka kapitel och stycken som ska finnas i en exjobbsrapport och ger viktiga tips om själva innehållet.\nAvslutningsvis  finns  en  tabell  som går  igenom skillnaderna  mellan ett exjobb på  grundnivå  och avancerad nivå.\nLäs  denna  anvisning  noga  innan  exjobbet  påbörjas  och  ha den alltid till hands under själva skrivandet.";
    }
    {
        Chapter & ch {rep.new_chapter("Inledning")};
        ch.text() = "Inledningen ska delas in i följande stycken.";
        {
            Chapter & sc {ch.add_subchapter("Motivering")};
            sc.text() = "Här  ska  det  studerade  problemet  översiktligt  beskrivas  och sättas  in  i  ett  sammanhang  som  gör  det  tydligt  att  det  är intressant  och  viktigt  att  studera  närmare. Målsättningen  är att göra läsaren intresserad av arbetet och skapa en vilja att läsa vidare.";
        }
        {
            Chapter & sc {ch.add_subchapter("Syfte")};
            sc.text() = "Vad är det som examensarbetet ska leda till?";
        }
    }
    rep.print(cout);
    /* Bör ge följande utskrift:
Anvisning för exjobbsrapporter
Åberg, Johan

Om denna handledning
Denna anvisning går igenom vilka kapitel och stycken som ska finnas i en exjobbsrapport och ger vikga tips om själva innehållet.
Avslutningsvis  finns  en  tabell  som går  igenom skillnaderna  mellan ett exjobb på  grundnivå  och avancerad nivå.
Läs  denna  anvisning  noga  innan  exjobbet  påbörjas  och  ha den alltid till hands under själva skrivandet.

Inledning
Inledningen delas in i följande stycken.

Motivering
Här  ska  det  studerade  problemet  översiktligt  beskrivas  och sättas  in  i  ett  sammanhang  som  gör  det  tydligt  att  det  är intressant  och  viktigt  att  studera  närmare. Målsättningen  är att göra läsaren intresserad av arbetet och skapa en vilja att läsa vidare.

Syfte
Vad är det som examensarbetet ska leda till?
*/
}
