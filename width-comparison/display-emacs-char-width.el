(defun read-lines (fp)
  "Return a list of lines of a file at filepath."
  (with-temp-buffer
    (insert-file-contents fp)
    (split-string (buffer-string) "\n" t)))

(defun write-line (line)
  (let* ((hex (replace-regexp-in-string "\n" "" line))
         (num (string-to-number hex 16))
         (width (char-width num)))
    (princ (format "%s %d\n" hex width))))

(defun write-lines (lines)
  (let ((line (car lines))
        (remains (cdr lines)))
    (write-line line)
    (if remains (write-lines remains))))

(defun main (langu-env file-path)
  (progn
    (set-language-environment lang-env)
    (let ((lines (read-lines file-path)))
      (while lines
        (write-line (car lines))
        (setq lines (cdr lines))))))

(let ((lang-env (nth 0 argv))
      (file-path (nth 1 argv)))
  (main lang-env file-path)
  (setq argv nil))
