(setq lang-env (nth 0 argv))
(setq filepath (nth 1 argv))
(set-language-environment lang-env)

(defun read-lines (filepath)
  "Return a list of lines of a file at filePath."
  (with-temp-buffer
    (insert-file-contents filePath)
    (split-string (buffer-string) "\n" t)))

(setq lines (read-lines filepath))
(while lines
  (setq hex (replace-regexp-in-string "\n" "" (car lines)))
  (setq num (string-to-number hex 16))
  (setq width (char-width num))
  (princ (format "%s %d\n" hex width))
  (setq lines (cdr lines)))


(setq argv nil)
