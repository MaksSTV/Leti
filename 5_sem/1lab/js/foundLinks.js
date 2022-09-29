function foundLinks(links) {
    const searchResults = document.querySelector('.add_ref');
  
    var newElem = '<div class="ref">'; 

    links.query.search.forEach(link => {
      const url = `https://ru.wikipedia.org/?curid=${link.pageid}`;

      newElem += '<a href="'+`${url}`+'">'+`${link.title}`+'</a>';
    });

    newElem += '</div>';
    searchResults.insertAdjacentHTML('beforeend', newElem);
  } 