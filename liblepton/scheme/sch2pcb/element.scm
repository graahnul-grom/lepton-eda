;;; Lepton EDA Schematic to PCB conversion
;;; Scheme API
;;; Copyright (C) 2023-2024 Lepton EDA Contributors
;;;
;;; This program is free software; you can redistribute it and/or modify
;;; it under the terms of the GNU General Public License as published by
;;; the Free Software Foundation; either version 2 of the License, or
;;; (at your option) any later version.
;;;
;;; This program is distributed in the hope that it will be useful,
;;; but WITHOUT ANY WARRANTY; without even the implied warranty of
;;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;;; GNU General Public License for more details.
;;;
;;; You should have received a copy of the GNU General Public License
;;; along with this program; if not, write to the Free Software
;;; Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

(define-module (sch2pcb element)
  #:use-module (system foreign)

  #:use-module (lepton ffi sch2pcb)

  #:export (free-element
            pcb-element-description
            set-pcb-element-description!
            pcb-element-pkg-name-fix
            set-pcb-element-pkg-name-fix!
            pcb-element-refdes
            set-pcb-element-refdes!
            pcb-element-value
            set-pcb-element-value!
            pkg-line->element))


(define (pcb-element-get-string *element *c-getter)
  (define *s (*c-getter *element))
  (if (null-pointer? *s)
      ;; What should the function return if *s is NULL?
      "<null>"
      (pointer->string *s)))

(define (pcb-element-set-string! *element *c-setter s)
  (define *s (if s (string->pointer s) %null-pointer))
  (*c-setter *element *s))

(define (pcb-element-description *element)
  (pcb-element-get-string *element pcb_element_get_description))

(define (set-pcb-element-description! *element description)
  (pcb-element-set-string! *element
                           pcb_element_set_description
                           description))

(define (pcb-element-refdes *element)
  (pcb-element-get-string *element pcb_element_get_refdes))

(define (set-pcb-element-refdes! *element refdes)
  (pcb-element-set-string! *element
                           pcb_element_set_refdes
                           refdes))

(define (pcb-element-value *element)
  (pcb-element-get-string *element pcb_element_get_value))

(define (set-pcb-element-value! *element value)
  (pcb-element-set-string! *element
                           pcb_element_set_value
                           value))

(define (pcb-element-pkg-name-fix *element)
  (pcb-element-get-string *element pcb_element_get_pkg_name_fix))

(define (set-pcb-element-pkg-name-fix! *element name-fix)
  (pcb-element-set-string! *element
                           pcb_element_set_pkg_name_fix
                           name-fix))


(define (pkg-line->element *line)
  (pcb_element_pkg_to_element *line))


(define (free-element *element)
  (pcb_element_free *element))