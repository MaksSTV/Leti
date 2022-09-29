async function getString() {

    let string = document.querySelector('.input_search').value;
    let response = string.trim();

    let searchResults = document.querySelector('.add_ref');
    searchResults.innerHTML = '';

    let results = await search(response);
    if (results.query.searchinfo.totalhits === 0) {
        alert('Ничего не найдено');
        return;
    }
    foundLinks(results);

}

const form = document.querySelector('.form_search');
form.addEventListener('submit', getString);