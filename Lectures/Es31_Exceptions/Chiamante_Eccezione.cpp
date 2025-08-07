orario sommaDueOrari(){
    try {
        orario o1, o2;
        cin >> o1 >> o2;
        return o1 + o2;
    }
    catch (err_sint)
        {cerr << "Errore di sintassi"; return orario();}
    catch (fina_file)
        {cerr << "Errore fine file"; abort();}
    catch (err_ore)
        {cerr << "Errore nelle ore"; return orario();}
    catch (err_minuti)
        {cerr << "Errore nei minuti"; return orario();}
    catch (err_secondi)
        {cerr << "Errore nei secondi"; return orario();}
}