/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    struct EasyStruct es;

    es.es_StructSize = sizeof(es);
    es.es_Flags = NULL;
    es.es_Title = "<FATAL ERROR>";
    es.es_TextFormat = "Fatal Error: %s";
    es.es_GadgetFormat = "OK";

    _GetResponse((struct Window*) BuildEasyRequest(NULL, &es, NULL, m));
    ShutDown();
