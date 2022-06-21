/*
 * pemkey.h
 *
 *  Created on: Jul 16, 2020
 *      Author: leopoldo
 */

#ifndef MAIN_PEMKEY_H_
#define MAIN_PEMKEY_H_

/*
 * Clave PRIVADA del dispositivo registrado en Google Cloud Platform - IotCore
 * https://cloud.google.com/iot/docs/how-tos/credentials/keys
 *
 * Crear claves publica y privada para cada dispositivo desde la consola de GCP con la herramienta OPENSSL
 * 
 * openssl req -x509 -nodes -newkey rsa:2048 -keyout rsa_lz_private.pem -out rsa_lz_cert.pem -subj "/CN=unused" -days 36500 
 *  
 * rsa_private.pem: The private key that must be securely stored on the device and used to sign the authentication JWT.
 * rsa_public.pem: The public key that must be stored in Cloud IoT Core and used to verify the signature of the authentication JWT.
 */

const char GCP_PEM_KEY[] =

"-----BEGIN PRIVATE KEY-----\n"
"MIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCn7UJj0Wfd4v32\n"
"DGJJflIBF10BjsMhBLXD6DwsNbW0K2LZFa6RHgwxK2k2eG5CHPHNcRnP/TuJmh60\n"
"EazFUoRyPEKYWU2LdCXbJg0WkFOwXP6w+aDE1Boyr4Nv4qepgzvHXr6Wy2nzoak3\n"
"6ICrkR9LEFQ4cF88zYVKAmomFW/mMdemXeYEcErMjL4EUajhUKTnWbpb/nTtjnMD\n"
"rLqb3fORZmE0oU8EsuptH44ZCU5PnsrvYSwnWnlp4i1mgjtHn7O38lH00kq5yEfo\n"
"CsHc3oPbIEmR6sTIM1ESMR7ZbCQXtI7Y0bQwxok7oX8AsK60FJN+dvggKRLtM5Ke\n"
"CjeKpFyNAgMBAAECggEAPdlrHGyiPt0+AIOrJ7p45aH/RXWZdO3RLKi6kOXvWL6q\n"
"F56evyA8CVgd1kwhAAS9IpfHlA2HAjVbnaLs6XhtA84iEQ7DOtu6na60H11lFY4K\n"
"2I/4oMYmKAjw9iKa8ho9yD6jH9Mn4O3n74mY6pf22KTZADiTO0fPEeU1x3UZ08Rq\n"
"rmPhNe0/VfkwX3qCy/nMK4Jx4PcgEkCl6kOkTP/0IjMNjtcse6k7veOPGiWLhWLI\n"
"766W4fZp5mXQowsUJ9UkNXeqkrx2Bs/sYezxGKy26RGIjxi5Dh7cbQkgjr0JbHuL\n"
"t0elPvoT3D1FGeREE7yOgnHQQZNeYZN54dZSIIALGQKBgQDfG+5i6BUU+aaMNEsR\n"
"PK+rYZ5qoNN8753cHSlR1onWH1hLXJxbxe/bi0xKHeaeu5GR4i+coUEcCsv7h4yN\n"
"55Zxufi8YyWfWGigSKYGTilmBGAHIEpXNDPutje71oIHJugI9AViPn3B1MaEOz/X\n"
"lVUJ0NiZEcmDrCVg9sPHA1q2EwKBgQDArsPEl6HEX1r1oP2jY5akqb34J9ggmNwp\n"
"P8vyNrNc/j/kZri+shzEcIWD77eHkFYfdzaKEQ/tWHjGNtH3PqK+KC/Xrjw4S5Gj\n"
"JgzoIGkOlxdLMo066prAbssbnYdJnepzPX1YN+g8soEdL1sZV4um9eHhMcIAg0di\n"
"s43sGOF23wKBgFIBuUDfn4gjL2WPfxwp20Q6UHlO/g2JIdQbX+m12to6kUC6HLra\n"
"6YwgCn2fufoUZbBinC+NUhpVmZ6ttysdub25psTQCK8mVua7bVMZ/buC1i0oYErn\n"
"ZENU9O11Ljwkv9synpv67kyFwiYuhQvf1u8RtdulnxVn/CFE8rc+82PDAoGAeWsn\n"
"rjCnHanBFdvXOSi+exEDxubEyPXKdqvfBsj1ifolpPYeIPz4J8mIOTXL/z8zJizn\n"
"T2WlFbmUkcNl2Fm+D/oe+9it1gO4yIhnxbb2vNz1LsuyN5gy4GRw1PwVjoxWezwa\n"
"Socgb29E8XEwBO4n8JQtPM0wJUaUq1veaRLcsR0CgYEA0EuCdF3XSbM8Ab6MYOcj\n"
"vbsHc1t97J9HrYWMgWfvfR6YE1HfASKbKUT2LvguNgAhK50PVndt0R5rlQrLQJNM\n"
"gV6NjKLWpYuaBID0Dj5Uan+laOFE1LkJFc/H+OPNcxF0wh7DRYZUtVfaWW+fDav/\n"
"BFmWu5WGKHi+ujQICgkwH5g=\n"
"-----END PRIVATE KEY-----\n";

#endif /* MAIN_PEMKEY_H_ */

