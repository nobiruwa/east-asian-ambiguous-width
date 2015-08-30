NodeList.prototype.forEach = Array.prototype.forEach;

window.addEventListener('load', function() {
  function emphasize(row) {
    var wcwidth = parseInt(row.querySelector('.wcwidth').innerHTML),
        emacsWidth = parseInt(row.querySelector('.emacs-width').innerHTML),
        char = row.querySelector('.char');
    if (wcwidth !== emacsWidth) {
      row.classList.add('gap');
    }
  }

  var rows = document.querySelectorAll('.row');
  rows.forEach(emphasize);
});
