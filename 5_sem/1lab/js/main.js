async function search(string) {

    let endpoint = `https://ru.wikipedia.org/w/api.php?action=query&list=search&prop=info&inprop=url&utf8=&format=json&origin=*&srlimit=10&srsearch=${string}`;
    
    let response = await fetch(endpoint);
    if (!response.ok) {
      throw Error(response.statusText);
    }
    let json = await response.json();

    return json;
}