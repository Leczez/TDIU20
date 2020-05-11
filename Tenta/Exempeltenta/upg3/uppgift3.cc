




int main()
{
    {
        Copy_Counter c1;
        {
            Copy_Counter c2;
            Copy_Counter c3{c1};
            Copy_Counter c4{c2};
            c3 = c4;
            c4 = c1;
            c2 = c4;
        } // Här skrivs 2 ut eftersom c2 kopieras till c4 som kopierats till c3
        Copy_Counter c5;
        c5 = c1; // här skrivs 0 ut, det finns inga kopieringar av c5 innan tilldelningen
    }// här skrivs 4 ut, c3 kopierar c1, c4 kopierar c1, c2 kopierar c4, c5 kopierar c1
}
